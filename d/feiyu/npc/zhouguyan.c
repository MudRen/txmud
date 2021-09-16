#include <ansi.h>
inherit NPC;

void create()
{
        set_name("周孤燕", ({ "zhou guyan","zhou","guyan"}) );
        set("gender", "女性" );
        set("age", 29);
        set("long", "这是一位绯雨阁的后起之秀。\n");
        set("combat_exp", 300000);
        set("per", 30);
	set("class","rain");
        set("int", 30); 
        create_family("绯雨阁", 4, "弟子");

        set_skill("unarmed",140);
        set_skill("force",140);
        set_skill("dodge",140);
        set_skill("parry",140);
        set_skill("sword",140);
        set_skill("jieqing-sword", 140);
        set_skill("suiyu-force", 140);
        set_skill("zuiyue-strike", 140);
        set_skill("piaoyu-steps", 140);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        set("attitude", "friendly");
        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

