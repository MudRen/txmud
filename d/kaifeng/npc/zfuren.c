inherit NPC;

void create()
{
        set_name("���긾��", ({ "zhongnian furen" , "furen"}) );
        set("gender", "Ů��" );
        set("age", 45);
        set("long", "���������椵�ĸ�ס�\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
