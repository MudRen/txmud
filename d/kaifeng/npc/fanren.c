inherit NPC;

void create()
{
        set_name("犯人", ({ "fan ren"}) );
        set("gender", "男性");
        set("age", 29);

        set("long","这是一个杀人不眨眼的犯人.\n");

        set("combat_exp", 50000);
        set("str",20);

	set("max_kee",800);
	set("max_gin",800);
	set("max_sen",800);
	set("attitude", "heroism");

	set_skill("unarmed",50);
        set_skill("force",200);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

