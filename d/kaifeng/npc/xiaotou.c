inherit NPC;

void create()
{
        set_name("С͵", ({ "xiao tou"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "һ����ü���۵�С͵��\n");

        set("combat_exp", 30000);

        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("unarmed",50);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
