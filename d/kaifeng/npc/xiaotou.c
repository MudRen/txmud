inherit NPC;

void create()
{
        set_name("小偷", ({ "xiao tou"}) );
        set("gender", "男性" );
        set("age", 32);
        set("long", "一个贼眉鼠眼的小偷。\n");

        set("combat_exp", 30000);

        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("unarmed",50);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
