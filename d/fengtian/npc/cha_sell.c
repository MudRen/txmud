// cha_sell.c

inherit F_DEALER;

void create()
{
        set_name("���ɩ", ({ "ma dasao" }) );
	set("title","����ϰ���");
        set("gender", "Ů��" );
        set("age", 35);
        set("long","����һλ����Ц�ݵ����긾Ů��\n");
        set("combat_exp", 50);

        set("attitude", "friendly");
        set("vendor_goods", ([
		LIQUID_DIR"bowl" : -1,
        ]) );

	set("sell_all_day",1);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
