// huiboss.c

inherit DRUGGER;

void create()
{
	set_name("������", ({"yi busi"}));

	set("title","�ش����ƹ�");

	set("long", @TEXT
�����ǻش����ƹ�
TEXT
        );
	set("gender","����");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// ҩ����ҹӪҵ��
	set("sell_all_day",1);

	set("vendor_goods", ([
		DRUG_DIR"medicine_ganmao":-1,
		DRUG_DIR"huandan":30,
		DRUG_DIR"s_hd":20,
	]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}