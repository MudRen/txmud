// huoji.c

inherit DRUGGER;

void create()
{
    set_name("С���", ({"xiao huoji"}));
	set("long", @TEXT
һ����ʮ�����С�����æ�Ÿ����˳�ҩ��
TEXT
        );
	set("gender","����");
	set("age",25);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// ҩ����ҹӪҵ��
	set("sell_all_day",1);

	set("vendor_goods", ([
		DRUG_DIR"medicine_ganmao":-1,
		DRUG_DIR"huandan":50,
		DRUG_DIR"s_hd":30,
	]) );

	setup();
    carry_object(__DIR__"obj/cloth")->wear();
}
