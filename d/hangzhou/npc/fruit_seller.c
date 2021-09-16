// fruit_seller.c

inherit F_DEALER;

void steal_it();

void create()
{
	set_name("伙计", ({ "huo ji" }) );
	set("title","水果店");

	set("long", "这是一位水果店的伙计。\n");

	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		"水果贩子说道：“买点水果吧，绝对新鲜。”\n",
		}));

	set("gender", "男性" );
	set("age", 28);

	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":10,
		__DIR__"obj/melon":10,
		__DIR__"obj/grape":10,
	]) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
