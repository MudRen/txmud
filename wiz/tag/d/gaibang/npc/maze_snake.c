// maze_snake.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("蟒蛇", ({ "mang snake"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一条凶狠的蟒蛇正在朝你吐信。\n");
        set("str", 30 + random(10));
        set("cor", 20 + random(10));
        set("int", 0 + random(10));
        set("con", 40 + random(10));
        set("kar", 0);
        set("per", 15);

        set("attitude", "killer");
        set("combat_exp", 100000);
        set("gin", 100);
        set("max_gin", 100);
        set("kee", 500);
        set("max_kee", 500);
        set("sen", 100);
        set("max_sen", 100);      
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set_temp("apply/attack", 40);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 15);

        setup();
}

void die()
{
        object me = query_temp("last_damage_from");
        object ob = this_object();
        object where = environment(ob);

        message("vision", "\n"+ ob->name() + "死了。\n", where);

        if(me->query("quest/public/snake_kill", 1))
        {
                object dan = new(__DIR__"obj/maze_snake_dan");
                dan->move(where);
                me->delete("quest/public/snake_kill");
                me->add("combat_exp", 10);
                tell_object(me, YEL"\n你杀死蟒蛇得到了 十 点实战经验。\n"NOR);
        }

        destruct(ob);
}
