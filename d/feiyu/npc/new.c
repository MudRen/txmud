#include <ansi.h>
inherit NPC;

void create()
{
        set_name("入门弟子", ({ "rumen dizi" , "dizi"}) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "这是一位入门不久的新弟子。\n");
        set("combat_exp", 20000);
        set("per", 30);
        set("attitude", "friendly");
        set("max_force",300);
        set("force",300);
        set("force_factor",50);
        create_family("绯雨阁", 9, "弟子");

        set_skill("dodge",100);
        set_skill("sword",100);
        set_skill("parry",100);
        set_skill("jieqing-sword", 100);
        set_skill("suiyu-force", 100);
        set_skill("zuiyue-strike", 100);
        set_skill("piaoyu-steps", 100);
        set_skill("force",100);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        setup();
        carry_object(__DIR__"obj/feiyujian")->wield();
        carry_object(__DIR__"obj/feiyushan")->wear();
}

