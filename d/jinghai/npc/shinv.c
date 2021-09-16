// shinv.c from mool

inherit NPC;
 
void create()
{
        set_name("侍女", ({"shi nv",}));
        set("long", "这是一位衣着朴素大户人家的丫鬟。\n");
        set("gender","女性");
        set("title","桃花山庄");

        set("chat_chance",5);
        set("chat_msg",({
        "侍女很幽怨的自言自语道:我的情哥哥在中原,哎!真想去和他相会啊。\n"
}));
        set("age",19);
        set("con",30);
        set("str",20);
        set("max_kee",500);
        set("max_gin",400);
        set("max_sen",500);

        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("literate",10);

        set("combat_exp",20000+random(20000));

        setup();
        carry_object("/d/jinghai/obj/saozhu")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

