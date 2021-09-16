inherit ITEM;

void create()
{
       set_name("天蝉步法", ({ "tianchan-steps book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "本");
        set("long",
"这本书上面只有一些字迹模糊的字句，似乎\n"
"写的是一些轻功口诀。\n");
        set("value", 800);
        set("material", "paper");
        set("skill", ([
        "name":         "tianchan-steps", // 武功名称,
        "exp_required": 100,    // 读此书需要的最低经验.
        "sen_cost":     15,      // 读书花的神.
        "difficulty":   25,      // 参看 /cmds/std/study.c
        "max_skill":    40,      // 能读到的最高等级.
]) );
        }
}
int is_tangmen_book() { return 1; }

