// yao_npc.c

inherit NPC;

#include <ansi.h>
int ask_xuelian(object me);
int is_quest_object() { return 1;}

int have = 1,time;

void create()
{
	set_name("无名", ({ "wu ming" }) );
        set("gender", "男性" );
        set("age", 47);
        set("long", "这是一位行色匆匆的中年人。\n");
        set(NO_KILL, 1);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set("inquiry",([
	"天山雪莲" : (: ask_xuelian :),
	"雪莲" : (: ask_xuelian :),
]));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_xuelian(object me)
{
	if(!have)
	{
		write(sprintf(CYN"%s说道：已经让别人买走了。\n"NOR,name()));
		return 1;
	}

	if(me->query("quest/shaolin_quest/asked_xuelian") != query("id"))
	{
		write(sprintf(CYN"%s说道：我好不容易才买到的，怎么能给你！。\n"NOR,name()));
		return 1;
	}

	write(sprintf(CYN"%s说道：我是好不容易才弄到的，花了我5两银子呢，
既然你急用就 5 两银子转让给你吧，
现在像我这种好人哪去找呀。\n"NOR,name()));
	me->set_temp("xuelian_60",1);
	return 1;
}

int accept_object(object me, object ob)
{
	object lian;

	if(!is_money(ob))
		return 0;

	if(!me->query_temp("xuelian_60"))
	{
		command("say 这世道连白给钱的事情都有，谢谢啦。");
		return 1;
	}

	if(ob->value() < 500)
	{
		command("say 5两银子已经是不赚钱给你了，你还要怎么着！");
		return 0;
	}

	lian = new(__DIR__"obj/xuelian");
	lian->move(this_object());

	command("say 好吧，就卖给你了，你也就是碰上我这个好人了。");
	command(sprintf("give tianshan xuelian to %s",me->query("id")));

	me->delete_temp("xuelian_60");
	me->delete_temp("asked_xuelian");
	me->set("quest/shaolin_quest/have",1);
	have = 0;
        call_out("go_away",3);

	return 1;
}

int heal_up()
{
	int t;

	if(!have && living(this_object()))
	{
		call_out("go_away",1);
		return 1;
	}

	t = time();

	if(!time)
		time = t;

	else if(t - time > 1200)
	{
		call_out("go_away",1);
		return 1;
	}

	return ::heal_up() + 1;
}

void go_away()
{
	if(!living(this_object()))
		return;

	if(environment())
		tell_object(environment(),name()+"匆匆忙忙地走了。\n");
	destruct(this_object());
}
