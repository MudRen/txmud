// shangyao
// by dicky

inherit ITEM;

void create()
{
        set_name("大内伤药", ({"dalei shangyao", "shangyao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包不起眼的伤药，但据说功效卓著。\n");
                set("value", 100);
		set("no_drop", 1);
                set("no_give",1);
                set("no_put",1);
        }
        setup();
}

void init()
{
        add_action("do_fu", "fu");
}

int do_fu(string arg)
{
        object me;
        me = this_player();
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        if( me->is_fighting() )
		return notify_fail("战斗中不能吃药疗伤！\n");
        if ((int)this_player()->query("eff_kee") ==
            (int)this_player()->query("max_kee"))
                return notify_fail("你现在没伤，瞎吃什麽药？\n");
        
        else {
                me->receive_curing("kee", 200);
                message_vision("$N服下一包伤药，伤势减轻了许多。\n", this_player());
                destruct(this_object());
                return 1;
        }
}
