inherit NPC;

void create()
{
        set_name("趟子手", ({ "tang zishou" , "tang" }) );
        set("gender", "男性" );
        set("age", 31);
        set("long", "这是一位天马镖局的趟子手。\n");

        set("combat_exp", 80000);
        set("str", 20);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 10);

        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("unarmed",60);
        set_skill("force",130);
        set_skill("sword",60);

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
