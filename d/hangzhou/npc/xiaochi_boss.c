// xiaochi_boss.c

inherit F_DEALER;

void create()
{
	set_name("���ƹ�", ({ "zhang gui" }) );
	set("title","С�Ե�");
        set("gender", "����" );
        set("age", 46);
	set("sell_all_day",1);
        set("long","���Ǻ���С�Ե���ƹ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/doujiang" : 20,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
