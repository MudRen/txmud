inherit NPC;

void create()
{
        set_name("���", ({ "huo ji" }) );
        set("gender", "����" );
        set("age", 19);
        set("long", "һ���������Ļ��.\n");

        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("parry", 10);
        set_skill("dodge", 10);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();        
}
