
inherit NPC;

void create()
{
        set_name("张妞妞", ({ "zhang niuniu" , "zhang"}) );
        set("gender", "女性" );
        set("age", 23);
        set("long", "张妞妞是跟着母亲从农村来的。\n");

        set("combat_exp", 1);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
