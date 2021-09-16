#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"『升仙诀』"NOR, ({ "xian book's copy"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "卷");
        set("long",
"原书相传是由得道的张仙人所著，记录了众多修炼吐\n"
"纳之术，对于想要修炼灵力、修道成仙的人来说无疑\n"
"是无价之宝。此书乃是原手卷的手抄本。\n");
        set("value", 200000);
        set("material", "paper");
        set("skill", ([
        "name":         "magic",    // 武功名称.
        "exp_required": 1000000,         // 读此书需要的最低经验.
        "sen_cost":     1,             // 读书花的神.
        "gin_cost":     1,             // 读书花的精.
        "difficulty":   26,            // 参看 /cmds/std/study.c
        "min_skill":    151,
        "max_skill":    200,           // 能读到的最高等级.
]) );
        }
}
