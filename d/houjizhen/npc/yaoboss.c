// yaoboss.c
// by dicky

inherit DRUGGER;

void create()
{
        set_name("�ż���", ({ "zhang jishi","boss","jishi"}) );
        set("title", "ҩ���ϰ�");
        set("gender", "����" );
        set("age", 55);
        set("long", "������ҩ�̵��Ű���������һλ�Һ����ߡ�\n");

       	set("combat_exp", 100);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
	set("sell_all_day",1);

        set("inquiry", ([
                "ץҩ" : "�����Ǹ�����õ�ҩ�꣬��Ҫʲô��",
        ]) );

        set("vendor_goods", ([
                __DIR__"obj/xuelian" : 4,
                __DIR__"obj/yao" : 10,
		DRUG_DIR"medicine_ganmao":-1,
		DRUG_DIR"huandan":50,
		DRUG_DIR"s_hd":30,
        ]) );

        setup();
        add_money("silver", 10);
        carry_object(ARMOR_DIR"cloth")->wear();
}
