// tongzi1.c

inherit NPC;

void greeting(object me);

void create()
{
	set_name("小书童", ({ "shu tong","tong"}) );
	set("gender", "男性" );
	set("age", 19);
        set("per", 35);

        set("long","这是一位清秀的小童子，头上梳着两个冲天揪。");

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
	command("tell "+me->query("id")+" "+
		me->name()+"你好！师傅说你这两天就会来的，让我把这个东西交给你。");
	command("tell "+me->query("id")+" 师傅正在东面(east)的房子里等你呢。");
	paper = new(__DIR__"obj/paper");
	paper->set_owner(me->name());
	paper->move(this_object());
	command("give book to "+me->query("id"));
	return;
}
