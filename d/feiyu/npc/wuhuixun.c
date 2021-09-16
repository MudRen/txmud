#include <ansi.h>
inherit NPC;

void create()
{
        set_name("吴回荀", ({ "wu huixun","wu","huixun"}) );
        set("gender", "女性" );
        set("age", 25);
        set("long", "这是一位绯雨阁的后起之秀。\n");
        set("combat_exp", 200000);
        set("per", 30);
        set("int", 25);
	set("class","rain");
        create_family("绯雨阁", 5, "弟子");

        set_skill("unarmed",110);
        set_skill("force",110);
        set_skill("dodge",110);
        set_skill("parry",110);
        set_skill("sword",110);
        set_skill("jieqing-sword", 110);
        set_skill("suiyu-force", 110);
        set_skill("zuiyue-strike", 110);
        set_skill("piaoyu-steps", 110);
 
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
