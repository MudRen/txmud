//servant.c 头人府的仆人。
inherit NPC;
void create()
{
        set_name("仆人", ({ "servant" }) );
        set("age", 28);
        set("long", "一位精明的仆人。\n");
        
        set("str",25);
        set("per",5);
//        set("inquery",(
//      "德木寺":"小僧就是德木寺的喇嘛。",
//]));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
