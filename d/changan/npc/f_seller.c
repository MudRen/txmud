// f_seller.c

inherit FURNITURE_SELLER;

void create()
{
	set_name("С���", ({ "huo ji" }) );
	set("gender", "����" );
	set("title","��˽��");
	set("age", 23);
	set("long", "����һλ����ǿ�ɵ������ˡ�\n");
	set("combat_exp", 100);
	set("str", 27);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 2);
	set("furnitures",({
	FUR_DIR"chuang",
	FUR_DIR"shuzhuo",
	FUR_DIR"shuzhuangtai",
}));
	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
