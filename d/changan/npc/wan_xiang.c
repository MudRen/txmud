// design by 发现号(find) . all right reserved.

// wan_xiang.c

#include <ansi.h>

inherit NPC;
void back_out(object who);
void create()
{
	set_name("婉香", ({ "wan xiang" }) );
	// 醉花轩 ji3
	set("gender", "女性" );
	set("age", 19);
	set("str", 25);
	set("per", 30);
	set("long", @LONG
她腰肢丰满，美目流盼，浑身上下散发着诱人的魅力。
LONG
);
	set("class","jiyuan");
	set("combat_exp", 100);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);

	setup();
	carry_object(__DIR__"obj/c_mirror");
	carry_object(__DIR__"obj/suihua_skirt")->wear();
}

void init()
{	
	object *inv;
	int i;

	::init();
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		{
		if(!inv[i]->query_temp("jiyuan/order")) continue;
		remove_call_out("greeting");
		call_out("greeting", 1, inv[i]);
		}
	add_action("do_sleep","come");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || !ob->query_temp("jiyuan/order")) return;
	message_vision("\n$N朝$n盈盈一福：奴家来伺候您了。奴叫婉香(wan xiang)。\n",this_object(),ob);
	message_vision("奴的「醉花轩」，让爷尝尝欲仙欲死的滋味。(accept wan xiang)\n",this_object());
}

int accept_object(object who,object ob)
{
	object obj;
	if(!who->query_temp("jiyuan/shangqian") || who->query_temp("jiyuan/shangqian") != "婉香") return 0;
	if(!ob->query("money_id")) return 0;
	if(ob->value() < 10000)
		{
		message_vision("$N说道：爷再多赏几个吧。\n",this_object());
		return 1;
		}
	if(obj = present("hong xiu",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	if(obj = present("lian yu",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	if(obj = present("xiang yu",environment())) {
		tell_object(environment(),obj->name()+"走了。\n");
		destruct(obj);
	}
	message_vision("$N高兴地说道：多谢$n大爷的赏。爷跟我来吧。",this_object(),who);
	who->set_leader(this_object());
	who->delete_temp("jiyuan");
	who->set_temp("jiyuan/sleep",this_object()->name());
	command("go south");
	call_out("can_sleeping",2,who);
	return 1;
}

void can_sleeping(object who)
{
	object mother;
	if( !who || environment(who) != environment() )
	{
	message_vision("$N叹了口气，走了。\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
	}
	message_vision("$N满脸羞红的往床边一靠。\n",this_object());
	command("remove skirt");
	message_vision(CYN"$N低声对$n说：爷快来(come)吧，奴家都...等不及了。\n"NOR,this_object(),who);
	call_out("waiting_you",3,who,0);
	return;
}


void waiting_you(object who,int n)
{
	remove_call_out("waiting_you");
	if( !who || environment(who) != environment() )
	{
		back_out(who);
		return;
	}

	switch (n)
	{
		case 0:
			message_vision(CYN"$N羞涩的看着$n说道：难道奴家的身子也还不满意。。。\n"NOR,this_object(),who);
			break;
		case 1:
			message_vision(CYN"$N捂着小脸看着$n说道：也这么盯着奴的光景看，真坏。。。\n"NOR,this_object(),who);
			break;
		case 2:
			message_vision(CYN"$N撅着小嘴对说道：爷到了奴这又不作，让奴真是。。。\n"NOR,this_object(),who);
			break;
	}

	if(n >= 2)
		back_out(who);
	else
	{
		n += 1;
		call_out("waiting_you",3,who,n);
	}
}

void back_out(object who)
{
	object mother;
	command("wear skirt");
	message_vision("$N叹了口气，走了。\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	if(who) who->delete_temp("jiyuan");
	destruct(this_object());
	return;
}

int do_sleep(string arg)
{
	object *inv,me = this_player();
	int i;
	if(!me->query_temp("jiyuan/sleep") || me->query_temp("jiyuan/sleep") != "婉香")
		return 0;
	if(find_call_out("waiting_you"))
		remove_call_out("waiting_you");
	message_vision("$N两眼通红，低吼一声扑向$n的胴体......\n",me,this_object());
	message_vision("$N突然觉得一阵晕眩......\n",me);
	me->delete_temp("jiyuan");
	me->unconcious();
	command("get all");
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
		{
		destruct(inv[i]);
		}
	call_out("go_out",1);
	return 1;
}

void go_out()
{
	object mother;
	command("wear skirt");
	message_vision("$N一阵冷笑，走了出去。\n",this_object());
	if(mother = present("m_boss",find_object("/d/changan/jiyuan")))
		mother->delete_temp("have_full");
	destruct(this_object());
}