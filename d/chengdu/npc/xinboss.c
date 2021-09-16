// xinboss.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("辛平", ({ "xin ping" }) );

	set("title","水果店老板");
	set("gender", "男性" );
	set("age", 32);
	set("per",18);

	set("sell_all_day",1);

	set("long","这是一位相貌忠厚的中年人，据说他在京城当过
乞丐，居然后来混成了一个小老板，真让人觉得
不可思议\n");

	set("combat_exp", 50);
	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/xuecheng":10,
		__DIR__"obj/liangpingyou":10,

]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( living(ob = previous_object()) && !is_fighting() && userp(ob))
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != query("startroom"))
		return;
 
        switch( random(3) )
        {
		case 0:
			say( CYN"辛平说道：这位" + RANK_D->query_respect(ob)
				+ "，请进。\n"NOR);
			break;
		case 1:
			say( CYN"辛平说道：这位" + RANK_D->query_respect(ob)
				+ "想要吃点什么水果？\n"NOR);
			break;
	}
}
