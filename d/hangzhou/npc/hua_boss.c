// hua_boss.c

inherit F_DEALER;

void create()
{
	set_name("程天香", ({ "cheng tian xiang" }) );
	set("title","花店女掌柜");
        set("gender", "女性" );
        set("age", 36);
	set("per",30);
	set("sell_all_day",1);
        set("long","他就是杭州花店的老板娘。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/rose" : 10,
		__DIR__"obj/mum" : 10,
		__DIR__"obj/hehua" : 10,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
