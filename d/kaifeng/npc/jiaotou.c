inherit NPC;

void create()
{
        set_name("武馆教头", ({ "jiao tou" }) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "武馆教头长的人高马大，一身横肉。\n");

	set("max_kee",900);
	set("max_gin",1500);
	set("max_sen",1500);

        set("combat_exp", 400000);
        set("str", 30);
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 10);

	set_skill("dodge",100);
	set_skill("parry",90);
        set_skill("unarmed",80);
        set_skill("force",140);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
