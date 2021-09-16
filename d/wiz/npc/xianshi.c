// xianshi.c

inherit NPC;

void greeting(object me);

int can_enter(object me)
{
	if(!me || !userp(me) || wizardp(me))
		return 0;

	if(!me->query_temp("read_book"))
		return 0;
	me->delete_temp("read_book");
	me->set_temp("end_quest",1);
	call_out("tell_player",1,me);
	return 1;
}

void create()
{
	set_name("大元仙师", ({ "dayuan xianshi","xianshi"}) );
	set("gender", "男性" );
	set("age", 99);
        set("per", 35);

        set("long","一位仙风道骨、慈眉善目的老者。");

        set("combat_exp", 20000);
        set("attitude", "friendly");
	setup();
        
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	if(!wizardp(this_player()))
		call_out("greeting",1,this_player());
}

void greeting(object me)
{
	object paper;

	if(environment(me) != environment())
		return;

	if(!objectp(paper = present("book",me))
	|| (paper->query("name") != me->name()+"的入住手册"))
		return;

	if(can_enter(me))
		return;

	command("tell "+me->query("id")+" 老朽算着你这两天就该来了，我送你的书(book)童子交给你了吧。
              先要好好看看(look)呀");
}

protected void tell_player(object me)
{
	command("tell "+me->query("id")+" 好了，你可以走(enter)了。江湖风险重重，望你好自为之。");
	return;
}
