// smith.c
inherit SMITH;
void create()
{
        set_name("ŷ������", ({"ousuo suolang","smith" }) );
        set("title","����");
        set("gender", "����" );
        set("age", 42);
        set("str",100);
        set("long", "һλ��������ĺ��ӡ�\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 100);

        set_weapon_ability(({"blade","spear", "staff"}));
        set_ability_level(10);

        setup();

        carry_object(ARMOR_DIR+"cloth")->wear();
}
