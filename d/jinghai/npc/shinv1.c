inherit NPC;
 
void create()
{
        set_name("侍女", ({"shi nv",}));
        set("long", "这是一位衣着朴素大户人家的丫鬟。\n");
        set("gender","女性");
        set("title","朱雀堂");

        set("chat_chance",5);
        set("chat_msg",({
        "侍女正在买力得打扫着房间。\n"
}));
        set("age",19);
        set("con",30);
        set("str",20);
        set("max_kee",500);
        set("max_gin",400);
        set("max_sen",500);

        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("unarmed",50);
        set_skill("literate",10);

        set("combat_exp",50000+random(20000));

        setup();
        carry_object(__DIR__"obj/saozhu")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

