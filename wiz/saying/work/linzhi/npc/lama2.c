//lama2.c 巴彦喇嘛，济嘎活佛的师弟。
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name("巴彦喇嘛", ({ "bayan lama","lama"}) );
        set("nickname", "热情似冰");
        set("gender", "男性" );
        set("age", 45);
        set("str", 103);
        set("cor", 50);
        set("cps", 30);
        set("int", 36);
        set("per", 16);
        set("con", 54);
        set("spi", 30);
        set("kar", 10);

        set("long",
"巴彦喇嘛是济嘎活佛的师弟，表面和蔼可亲，实际
上却是冷酷无情，他主修大手印功法，不过有冰火
两重劲力的掌法到他这里却只有更冷。\n");

        set("combat_exp", 2500000);
        set("attitude", "friendly");

        set("max_atman", 1000);
        set("atman", 1000);
        set("max_kee",2300);
        set("max_force", 4500);
        set("force", 9000);
        set("force_factor", 120);
        set("max_mana", 800);
        set("mana", 800);

        set_skill("blade", 220);
        set_skill("unarmed",240);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("force", 220);
//        set_skill("fire-blade", 220);
//        set_skill("dashouyin", 240);
//        set_skill("jimie-steps", 220);
//        set_skill("mizong-xinfa", 220);
//        map_skills("blade","fire-blade");
//        map_skills("unarmed","dashouyin");
//        map_skills("parry","fire-blade");
//        map_skills("dodge","jimie-steps");
//        map_skills("force","mizong-xinfa");
        
        setup();
        carry_object(__DIR__"obj/zang-blade")->wield();
        carry_object(__DIR__"obj/cassock")->wear();
}

//int do_fight();
//想法如下：模仿华山地牢的盗贼，如果player赢了他，求饶，去工巴寺拿书。
