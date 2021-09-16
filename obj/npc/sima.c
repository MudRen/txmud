// by uudd.
// sima.c
// 玩家更名物件.
#include <ansi.h>

#define BASE_CHANGE_COST 100   //基本的改名费用，单位 gold.

inherit NPC;

private string change_name();
private int comput_cost(object me);
private void dest_objects();

void create()
{
	// ***** This object's name must be "banned". *****
	// I think the environment of this object may be set "no_fight".
	set_name("司马良", ({ "sima liang", "sima", "liang" }));
	set("title", "户部堂官");

	set("str", 20);
	set("gender", "男性");
	set("age", 35);
	set("long",
"司马良是当朝户部堂官，由于清廉自守，深得
朝廷信任，被派往户部专司户籍，小民更名改
姓的一些小事情也由他掌管。\n");

	set("combat_exp", 150);
	set("attitude", "friendly");
	set("inquiry", ([
	"改名" : (: change_name :),
	"更名" : (: change_name :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_name","change");
}
 
void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	if(!is_day())
		return;

	switch(random(2))
	{
		case 0 :
			command("say 这位"+RANK_D->query_respect(ob)+"来见本官有何事情？\n");
			break;
		case 1 :
			command("say 现在只办理更名事宜，其他事情就请回吧。\n");
			break;
	}
}

private string change_name()
{
	object me = this_player();

	if(!is_day())
		return "现在已经歇衙了，请早八点到晚九点前来办理。\n";
	return me->name() + "要更名须先交" +
		chinese_number(comput_cost(me)) + "两黄金的更名手续费。\n";
}

private int comput_cost(object me)
{
	int times;

	if(times = me->query("changed_name"))
		// 每更名一次，下次要多收 50 gold.
		return BASE_CHANGE_COST + times * 50;
	else return BASE_CHANGE_COST;
}

int accept_object(object who, object ob)
{
	if(!is_day())
	{
		command("say 现在已经歇衙了，请早八点到晚九点前来办理。\n");
		return 0;
	}

	if(!ob->query("money_id"))
	{
		command("say 户部不是收破烂的，要更名交现金！\n");
		return 0;
	}

 	if( ob->value() >= comput_cost(who)*10000 )
	{
		command("say "+who->name()+"更名费收讫，想好新的中文名字后：change 新的中文名字\n");
		who->set_temp("paid_changename_cost",1);
		call_out("dest_objects",1);
		return 1;
	}

	else
	{
		command("say "+who->name() + "要更名需要交" +
		chinese_number(comput_cost(who)) + "两黄金的更名手续费。\n");
		return 0;
	}
}

int do_name(string target)
{
	object me = this_player();

	if(!is_day())
	{
		command("say 现在已经歇衙了，请早八点到晚九点前来办理。\n");
		return 1;
	}

	if( !me->query_temp("paid_changename_cost") ) 
		return notify_fail(me->name() + "要更名需要交" +
			chinese_number(comput_cost(me)) + "两黄金的更名手续费。\n");

	if( !target || target==" ") 
		return notify_fail("change 新的中文名字\n");

	if( target == me->name() )
		return notify_fail("怎么？还是原来的名字？要戏弄本官吗？\n");

	message_vision("$N拿起一个大本子仔细的查了起来。\n",this_object());
	call_out("do_change",1,me,target);
	return 1;
}

private void do_change(object me,string target)
{
	object link_ob,mailbox,ob = find_object(LOGIN_D);

	if(!ob)
	{
		say("Bug! Can not find LOGIN_D!! Please report to wizards!!\n");
		return;
	}

	if(!ob->check_legal_name(target))
	{
		say("再想一个吧。\n");
		return;
	}

	change_cname(me->query("id"),target);

	link_ob = me->query_temp("link_ob");
	PLAYERHOME_D->home_master_change_cname(me,me->name(),target);

        NEWS_D->add_news_item( sprintf(HIY"%s(%s) 在户部注册正式更名为 \"%s\"。\n"NOR,
                me->name(),capitalize(me->query("id")),target ),"p", 1);

	command("chat " +"\""+ me->name() + "\""+"在户部注册更名为：" +
		"\""+target + "\""+"。大家以后不要认错了人了！\n");
	me->delete_temp("paid_changename_cost");
	me->add("changed_name",1);
	me->set("name", target);
	link_ob->set("name", target);

	mailbox = present("mailbox",me);
	if(mailbox)
		mailbox->set_name( me->name(1) + "的信箱",({ "mailbox", "box" }) );

	me->save();
	link_ob->save();
	return;
}

private void dest_objects()
{
	int i;
	object *inv;

	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id") == "cloth")
			continue;
		destruct(inv[i]);
	}
}
