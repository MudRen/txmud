// huiboss.c

inherit DRUGGER;

void create()
{
	set_name("ÒÀ²»ËÀ", ({"yi busi"}));

	set("title","»Ø´ºÌÃÕÆ¹ñ");

	set("long", @TEXT
Ëû¾ÍÊÇ»Ø´ºÌÃÕÆ¹ñ¡£
TEXT
        );
	set("gender","ÄĞĞÔ");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// Ò©ÆÌÖçÒ¹ÓªÒµ¡£
	set("sell_all_day",1);

	set("vendor_goods", ([
		DRUG_DIR"medicine_ganmao":-1,
		DRUG_DIR"huandan":30,
		DRUG_DIR"s_hd":20,
	]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}