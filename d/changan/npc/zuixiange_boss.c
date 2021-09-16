// zuixiange_boss.c

inherit F_DEALER;

void create()
{
	set_name("刘福", ({ "liu fu","boss" }) );
	set("title","谪仙楼掌柜");
	set("gender", "男性" );
	set("age", 45);
	set("long",
		"他就是谪仙楼的老板，由于人勤快，人缘又好，祖传的小店到他手里越做越大。\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("vendor_goods",([
	__DIR__"obj/yuxiang":3,
	__DIR__"obj/tuofeng":5,
	__DIR__"obj/yuchi":3,
	__DIR__"obj/yinyu":5,
	__DIR__"obj/shizi_tou":10,
	__DIR__"obj/taxue":5,
]));
	setup();
	add_money("silver",10);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!is_day())	return;
	switch( random(2) ) {
		case 0:
			say( "掌柜的笑咪咪地说道：您老用饭吧？快里面请。\n");
			break;
		case 1:
			say( "掌柜的笑咪咪地说道：请进请进，在这用饭保您满意。\n");
			break;
	}
}