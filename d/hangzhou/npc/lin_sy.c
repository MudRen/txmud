// lin_sy.c

inherit NPC;
 
void create()
{
	object ob;

        set_name("林福南", ({"lin funan"}));
	set("title","林家少爷");

	set("long", "这位就是杭州林家的大少爷，平时鱼肉乡里，
无恶不作。总因为家里有钱聘请了不少武林
人物，也学了一身不错的武功，所以也没人
敢惹。\n");
	set("gender","男性");

        set("age",28);
        set("con",30);
        set("str",30);
	set("kar",30);

	set("max_kee",1200);
	set("max_gin",2000);
	set("max_sen",2000);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",20);

	set_skill("unarmed",150);
	set_skill("sword",100);
	set_skill("parry",120);
	set_skill("dodge",120);
	set_skill("force",200);
	set_skill("lianhuan-sword",80);

	map_skill("sword","lianhuan-sword");
	map_skill("parry","lianhuan-sword");

	set("combat_exp",250000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	ob = carry_object(__DIR__"obj/liuxing_sword.c");
	if(ob)
		ob->wield();
}
