//fire_book1.c 火焰刀法高级书籍。
inherit ITEM;

void create()
{
        set_name("『火焰刀法』", ({ "fire-blade book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long","火焰刀法基本刀法。\n");
        set("NO_SELL",1);
        set("material", "paper");
        set("skill", ([
        "name" :          "fire-blade",        // 武功名称.
        "exp_required" :  200000,         // 读此书需要的最低经验.
        "difficulty" :    52,           // 参看 /cmds/std/study.c
        "max_skill" :     70,           // 能读到的最高等级.
]) );
        }
}
