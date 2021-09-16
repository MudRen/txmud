#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"小白兔"NOR, ({ "xiao baitu", "baitu" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只雪白漂亮的小白兔。\n");
        set("attitude", "peaceful");
 
        set("limbs", ({ "头部", "身体", "爪子", "尾巴" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 100);

        set_temp("apply/attack", 10);
        set_temp("apply/damage", 6);
        set_temp("apply/defence",10);
        set_temp("apply/armor",10);

        setup();
}

void die()
{
        object ob;
        message_vision("\n$N叫了几声，$N死了。\n", this_object());
        ob = new(__DIR__"obj/turou");
        ob->move(environment(this_object()));
        destruct(this_object());
}

