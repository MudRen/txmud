inherit NPC;
 
void create()
{
        set_name("婴孩", ({"baby",}));
        set("long", "一个眉青目秀的小孩子。\n");
        set("gender","男性");

        set("age",6);
        set("con",30);
        set("str",10);
 
        set("combat_exp",100+random(100));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

