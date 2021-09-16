// suicide.c
// Edit by Hao@ES2    30/04/98
// now suicide -f can delete the user mail.

// Modified by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
 	if( !arg )
	{
		write(HIY "提醒：您执行的是自杀指令！！！.\n" NOR );
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("自杀的指令格式为：suicide -f .\n");

	if(me != this_player(1))
		return 0;

	if(wizardp(me))
		return notify_fail("巫师不能自杀，请先向神申请降级。\n");

	write( HIY "您选择了永远死掉的自杀方式，这个人物的资料将被永远删除。\n" NOR
		   HIR "确定的话请输入您的密码：" NOR);

	seteuid(getuid());

	input_to("check_password", 1, me, 1);
	return 1;
}

protected void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass,temp_time;
	int loop;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");

	if( crypt(passwd, old_pass)!=old_pass )
	{
		write("密码错误！\n");
		return;
	}

	if(forever)
	{
		tell_object( me,HIR "\n\n您决定要自杀了，如果您后悔的话，请在20秒钟内使用quit指令退出。\n\n\n" NOR);
		for (loop=1;loop<20;loop++)
		{
			if (loop%5==0)
			{
				temp_time = (string) loop;
				call_out("show_message",20-loop,me,temp_time);
			}
		}
		call_out("slow_suicide",20,me);
	}
}

void show_message(object ob,string time)
{
	if(!ob)
		return;
	tell_object(ob, HIR "你还有 " + time + " 秒的时间可以后悔。\n" NOR);
}

protected int slow_suicide(object me)
{
	object link_ob;
	string id,mailfile;

	if(!me)
		return 0;

	link_ob = me->query_temp("link_ob");

	if( !link_ob ) return 0;

	log_file("suicide",sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );

	id = geteuid(me);

	mailfile=DATA_DIR+ "mail/" + sprintf("%c",id[0]) + "/" + id + ".o";
	if(file_size(mailfile) >= 0)
		rm(mailfile);

	write("好吧，永别了:)。\n");

	tell_room(environment(me), me->name() + "自杀了，以后你再也看不到这个人了。\n", ({me}));

	message("channel:sys", sprintf(HIR"【系统】%s(%s)自杀了。\n"NOR, me->name(), id),
		filter_array(users(),(: wizardp :)));

	if(environment(me) != find_object("/d/wiz/register"))
	{
		//NEWS_D->add_news_item( sprintf("%s(%s) 实在无法忍受这个荒唐的世界，彻底了断了自己。\n",
		//	me->query("name"),capitalize(id)),"p", 1);
		del_user_data(id,1);
	}
	else
		del_user_data(id,2);

	destruct(me);
	PLAYERHOME_D->delete_player_home(id,2);

	rm( DATA_DIR+ sprintf("login/%c/%s.o",id[0],id) );
	rename(DATA_DIR +sprintf( "user/%c/%s.o",id[0],id),BACKUP_DIR+id+".o");

	return 0;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
 
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重使用。
 
HELP
);
        return 1;
}
