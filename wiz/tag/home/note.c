// note.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC "备忘录" NOR, ({ "note" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
HIC"备忘录上写着：\n"NOR
"目前的首要任务是建立起一个便于记录的快捷备忘录，支持快速编辑，\n"
"从而明确目标，进行进一步的编写程序。\n"
                );

                set("value", 1);
                set("unit", "张");
        }
        setup();
}

