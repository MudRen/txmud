// hua_boss.c

inherit F_DEALER;

void create()
{
	set_name("������", ({ "cheng tian xiang" }) );
	set("title","����Ů�ƹ�");
        set("gender", "Ů��" );
        set("age", 36);
	set("per",30);
	set("sell_all_day",1);
        set("long","�����Ǻ��ݻ�����ϰ��\n");
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
