inherit NPC;

void create()
{
        set_name("�ٱ�", ({ "guan bing" }) );
        set("gender", "����" );
        set("age", 25);
        set("long", "�ٱ�������û��һ˿��Ц�ݡ�\n");
	set("vendetta_mark", "guanfu");

	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);

        set("combat_exp", 400000);
        set("str", 30);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 50);

        set_skill("dodge",240);
        set_skill("parry",140);
        set_skill("sword",120);
        set_skill("force",100);

        setup();
        carry_object(WEAPON_DIR"sword")->wield();       
        carry_object(ARMOR_DIR"cloth")->wear();
}
