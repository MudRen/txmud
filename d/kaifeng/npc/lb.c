inherit NPC;

void create()
{
        set_name("李镖师", ({ "li biaoshi" , "biaoshi" , "li" }) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "陈镖师在镖局已经很多年了。\n");

        set("combat_exp", 100000);
        set("str", 20);
        set("int", 30);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 10);

        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",60);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
