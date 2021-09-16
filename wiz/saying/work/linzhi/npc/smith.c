// smith.c
inherit SMITH;
void create()
{
        set_name("欧索索朗", ({"ousuo suolang","smith" }) );
        set("title","铁匠");
        set("gender", "男性" );
        set("age", 42);
        set("str",100);
        set("long", "一位精赤上身的汉子。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 100);

        set_weapon_ability(({"blade","spear", "staff"}));
        set_ability_level(10);

        setup();

        carry_object(ARMOR_DIR+"cloth")->wear();
}
