inherit NPC;
 
void create()
{
        set_name("渔民", ({"fisher man",}));
        set("long", "这是一位衣着破破烂烂得糟老头子。\n");
        set("gender","男性");

        set("chat_chance",2);
        set("chat_msg",({
        "渔民叹气道：我在这里就靠打渔为生，.....半辈子啦。\n"
}));
        set("age",59);
        set("con",30);
        set("str",20);
      
        set_skill("dodge",10);
        set_skill("parry",10);
        set_skill("unarmed",10);

        set("combat_exp",1000+random(1000));

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}


