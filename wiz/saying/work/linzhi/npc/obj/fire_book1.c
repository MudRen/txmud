//fire_book1.c 火焰刀法高级书籍。
inherit ITEM;
inherit F_CONTROL;

void create()
{
        set_name("『火焰刀法』", ({ "advanced fire-blade book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long","火焰刀法进阶刀法。\n");
        set("NO_SELL",1);
        set("NO_DROP",1);
        set("NO_GET",1);
        set("material", "paper");
        set("skill", ([
        "name" :          "fire-blade",        // 武功名称.
        "exp_required" :  1000000,         // 读此书需要的最低经验.
        "skill_required" :  70,         // 读此书需要的最低经验.
        "sen_cost" :      40,            // 读书花的神.
        "difficulty" :    52,           // 参看 /cmds/std/study.c
        "min_skill" :     70, 
        "max_skill" :     200,           // 能读到的最高等级.
]) );
        }
}
