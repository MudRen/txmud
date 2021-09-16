inherit NPC;

void create()
{
        set_name("胡镖师", ({ "hu biaoshi" , "biaoshi" , "hu" }) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "胡镖师在镖局已经很多年了。\n");

        set("combat_exp", 150000);
        set("str", 20);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 10);

        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("unarmed",70);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
