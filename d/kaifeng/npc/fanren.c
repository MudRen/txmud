inherit NPC;

void create()
{
        set_name("����", ({ "fan ren"}) );
        set("gender", "����");
        set("age", 29);

        set("long","����һ��ɱ�˲�գ�۵ķ���.\n");

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

