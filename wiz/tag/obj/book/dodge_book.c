/*
/obj/book/ 
*/

inherit ITEM;

void create()
{
        set_name("『轻功入门』", ({ "dodge book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long",
"这是一本介绍纵跃闪躲之术的书，内容甚浅。\n"
        );
        set("value", 3000);
        set("material", "paper");
        set("skill", ([
        "name" :          "dodge",      // 武功名称.
        "exp_required" :  1000,         // 读此书需要的最低经验.
        "sen_cost" :      1,            // 读书花的神.
        "difficulty" :    22,           // 参看 /cmds/std/study.c
        "max_skill" :     50,           // 能读到的最高等级.
]) );
        }
}
