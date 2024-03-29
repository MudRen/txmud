#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"『薛氏文集』"NOR+"中册", ({ "xue's 2nd book"}));
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "册");
        set("long",
"薛大学士所著作的文集，乃是读书人无限向往得到的\n"
"好书。由于发行的少，而中下册又多被损毁，所以使\n"
"得一套完整的文集更加宝贵。\n");
        set("value", 40000);
        set("material", "paper");
        set("skill", ([
        "name":         "literate",    // 武功名称.
        "exp_required": 50000,         // 读此书需要的最低经验.
        "sen_cost":     1,             // 读书花的神.
        "gin_cost":     1,             // 读书花的精.
        "difficulty":   22,            // 参看 /cmds/std/study.c
        "min_skill":    101,
        "max_skill":    160,           // 能读到的最高等级.
]) );
        }
}
