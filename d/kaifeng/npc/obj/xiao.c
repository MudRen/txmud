inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG"竹箫"NOR, ({ "zhu xiao" , "xiao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根竹子做的箫。\n");
                set("value", 100000);
        }
}
void init()
{
        add_action("do_chui","chui");
}
int do_chui(string arg)
{
        object me;
        me = this_player();
        if (arg != "xiao" && arg != "箫")
                return notify_fail("你要吹什么？\n");
        if (me->query_temp("marks/louth_chui"))
                return notify_fail("你正在吹奏着呢。\n");
                message_vision(MAG"$N拿起竹箫，吹起了动人的旋律。\n\n"NOR,me);
                me->set_temp("marks/louth_chui",1);
                call_out("qu", 8, me);
                me->start_busy(4);
                return 1;
}
int qu()
{
        object me=this_player();
        message_vision(MAG"$N一曲吹完，好似神仙一般。\n"NOR,me);
        me->delete_temp("marks/louth_chui");
        return 1;
}

