inherit NPC;

void create()
{
        set_name("陈镖师", ({ "chen biaoshi" , "biaoshi" , "chen" }) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "陈镖师在镖局已经很多年了。\n");

	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
        set("combat_exp", 200000);
        set("str", 25);
        set("int", 30);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 10);

	set_skill("dodge",90);
	set_skill("parry",90);
	set_skill("unarmed",60);
	set_skill("force",100);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
