// f_seller.c

inherit FURNITURE_SELLER;

void create()
{
	set_name("小伙计", ({ "huo ji" }) );
	set("gender", "男性" );
	set("title","家私城");
	set("age", 23);
	set("long", "这是一位精明强干的年轻人。\n");
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
