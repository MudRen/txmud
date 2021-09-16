#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"『升仙诀』"NOR, ({ "xian book"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "卷");
        set("long", @LONG
此手卷乃是由得道的张仙人所著，记录了众多修炼吐纳之
术，乃是无价之宝。多少年来无数道士耗费终生，就为了
得到这么一卷书而已。
LONG
        );
        set("value", 500000);
        set("material", "paper");
        set("skill", ([
        "name":         "magic",    // 武功名称.
        "exp_required": 2000000,         // 读此书需要的最低经验.
        "sen_cost":     1,             // 读书花的神.
        "gin_cost":     1,             // 读书花的精.
        "difficulty":   26,            // 参看 /cmds/std/study.c
        "min_skill":    101,
        "max_skill":    300,           // 能读到的最高等级.
]) );
        }
}
