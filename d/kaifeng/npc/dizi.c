inherit NPC;

void create()
{
        set_name("武馆弟子", ({ "wuguan dizi" , "dizi" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long", "一个武馆的记名弟子。\n");

	set("max_kee",700);
	set("max_gin",700);
	set("max_sen",700);

        set("combat_exp", 30000);
        set("str", 20);
        set("int", 30);

	set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",40);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
