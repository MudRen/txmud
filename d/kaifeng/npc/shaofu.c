inherit NPC;

void create()
{
        set_name("�ٸ�", ({ "shao fu"}) );
        set("gender", "Ů��" );
        set("age", 42);
        set("long", "�ٸ��������Ӷ�ˡ�\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
