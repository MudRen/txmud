inherit NPC;

void create()
{
        set_name("�˶�", ({ "qian er" }) );
        set("gender", "Ů��");
        set("age", 19);
        set("long", "�˶�����С�����硣\n");

        set("combat_exp", 1000);
        set("per", 30);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
