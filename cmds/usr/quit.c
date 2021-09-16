// quit.c
// Modified by Find.

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

protected string force_quit = "68#@";
protected void do_quit(object me);

int main(object me, string arg)
{
	object link_ob;
	int time;

	if(me->query("building_home"))
		return notify_fail("办理建房手续期间要求本人在场，等一会儿再走吧。\n");

	if(me->query_temp("be_in_sale_meeting_chu"))
		return notify_fail("你正在参加拍卖大会的竞买，等一会儿再走吧。\n");

	link_ob = me->query_temp("link_ob");
        if( link_ob )
	{
                if( link_ob->is_character() )
		{
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

		time = time() - link_ob->query("last_on");

                link_ob->set("last_out", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
                destruct(link_ob);
        }

	write("你决定离开"+MUD_NAME+"，档案保存中......\n");

	if(me->in_array())
	{
		if(me->is_array_master())
			me->release_array(2);
		else if(me->query_array_master())
			(me->query_array_master())->dismiss_array_member(me,2);
	}

	if(me->in_team())
		me->dismiss_team();

	if(wizardp(me) || (arg == force_quit))
		do_quit(me);
	else
	{
		me->start_busy(8);
		call_out("do_quit",3,me);
	}
	return 1;
}

protected void do_quit(object me)
{
	object *inv,rided;
	int i;

	if(!me)
		return;

        if( !wizardp(me) )
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if( !inv[i]->query_autoload() && !inv[i]->is_self_object())
			{
				DROP_CMD->do_drop(me, inv[i]);
				continue;
			}
#ifdef WIZARD_FLAG
			if(inv[i]->query_wiz_flag())
			{
				sys_log("wiz_ob",
				sprintf("(%s)身上存有违禁品(%s)被没收.\n",
				geteuid(me),base_name(inv[i])));
				destruct(inv[i]);
				continue;
			}
#endif
		}
        }

// modify by find. 玩家如骑在坐骑上,quit 会自动更新坐骑.
	if( rided=me->query_temp("on_rided") ) 
	{
		rided->delete_temp("have_been_rided");
		rided->set_leader(0);
	}
// over.

        tell_object(me, BWHT HIY"\n欢迎下次再来！\n\n"NOR);

	tell_room(environment(me), me->name() + "离开游戏。\n",
		filter_array( all_inventory(environment(me)), "filter_invisible", this_object(),me ) );

	message("channel:sys", sprintf(HIR"【系统】离线指令：%s(%s)离开游戏了。\n"NOR,
		me->name(1), me->query("id")),
		filter_array(users(),(: wizardp :)));

        me->save();
	seteuid(getuid());
	//me->set_temp("block_msg/all",1);
	destruct(me);
}

int filter_invisible(object ob,object user)
{
	if(ob == user)
		return 1;
	if( !userp(ob) )
		return 1;
	if( !ob->visible(user) )
		return 1;
	return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : quit

当你想暂时离开这个世界时, 可利用此一指令。
HELP
    );
    return 1;
}
