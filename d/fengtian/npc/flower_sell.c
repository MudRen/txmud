// flower_sell.c

inherit F_DEALER;

void create()
{
	set_name("����Ů", ({ "flower seller" }) );
	set("gender", "Ů��" );
	set("age", 15);
	set("long","����һλ�����СŮ����\n");
	set("combat_exp", 50);

	set("attitude", "friendly");
	set("vendor_goods", ([
		__DIR__"obj/rose" : 15,
		__DIR__"obj/y_rose" : 15,
		__DIR__"obj/w_rose" : 15,
		__DIR__"obj/baihe" : 15,
		__DIR__"obj/ju" : 15,
	]) );

	set("sell_all_day",1);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
