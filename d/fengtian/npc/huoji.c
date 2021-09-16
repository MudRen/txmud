// huoji.c

inherit DRUGGER;

void create()
{
	set_name("小伙计", ({"huo ji"}));
	set("long", @TEXT
一个二十多岁的小伙计正忙着给客人称药。
TEXT
        );
	set("gender","男性");
	set("age",25);
	set("con",20);
	set("str",20);
	set("combat_exp",200);

	// 药铺昼夜营业。
	set("sell_all_day",1);

	set("vendor_goods", ([
		DRUG_DIR"medicine_ganmao":30,
		DRUG_DIR"huandan":20,
		DRUG_DIR"s_hd":20,
	]) );

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
