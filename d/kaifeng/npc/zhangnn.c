
inherit NPC;

void create()
{
        set_name("����", ({ "zhang niuniu" , "zhang"}) );
        set("gender", "Ů��" );
        set("age", 23);
        set("long", "�����Ǹ���ĸ�״�ũ�����ġ�\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
