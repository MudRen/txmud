// tea_boss.c

inherit F_DEALER;

void create()
{
	set_name("���ƹ�", ({ "zhao zhanggui" }) );
	set("title","��Ҷ��");
        set("gender", "����" );
        set("age", 46);
	set("sell_all_day",1);
        set("long","���ƹ�ר�ž�Ӫ������������������\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/longjing" : 20,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
