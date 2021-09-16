// xianling.c

inherit NPC;
 
void create()
{
	set_name("园进宝", ({"yuan jinbao", "yuan", "xianling"}));
	set("title","长安县令");

	set("long", @LONG
他就是长安城的县令。长安县令历来是最难做的
官，由于长安是京师，上头高官如云，不比外阜
官员来的自在，但园进宝不知用什么手段上下通
融，竞深得朝野上下的好评。
LONG
);

	set("gender","男性");
	set("vendetta_mark", "guanfu");
	set("attitude","peaceful");

        set("age",45);

	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);

	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);

        set("combat_exp",600000+random(200000));

        setup();
        carry_object(__DIR__"obj/guanfu")->wear();
}
