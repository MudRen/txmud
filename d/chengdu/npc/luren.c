inherit NPC;

void create()
{
        set_name("·��", ({ "lu ren" }) );
        set("gender", "����" );
        set("age", 36);
        set("long",
                "����һλ�����ɶ���·�ˡ�\n");
        set("combat_exp", 1000);

	set_skill("unarmed",20);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

