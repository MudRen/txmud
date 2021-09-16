// fruit_seller.c

inherit F_DEALER;

void steal_it();

void create()
{
	set_name("水果贩子", ({ "fruit seller","seller" }) );
	set("long", "一个卖水果的小贩，正在起劲的向行人兜售水果。\n");

	set("sell_all_day",1);

	set("chat_chance", 5); /*随机动作的概率*/
	set("chat_msg",({
		"水果贩子说道：“买点水果吧，绝对新鲜。”\n",
		"水果贩子说道：“公平交易，童叟无欺。”\n",
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
		__DIR__"obj/pear":10,
		__DIR__"obj/grape":10,
	]) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
