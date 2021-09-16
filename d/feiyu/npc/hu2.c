#include <ansi.h>
inherit NPC;

void create()
{
        set_name("红缃", ({ "hong xiang","xiang" , "hu wei"}) );
        set("title",RED"绯雨阁四大护法"NOR);
        set("gender", "女性" );
	set("class","rain");
        set("age", 28);
        set("long", "绯雨阁的四大护法在江湖上有名气。\n");
        set("combat_exp", 2000000);
        set("max_force",2500);
        set("force",2500);
        set("force_factor",200);
        set("per", 30);
        set("str", 30); 
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);

        set_skill("unarmed",200);
        set_skill("force",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("sword",200);
        set_skill("jieqing-sword", 200);
        set_skill("suiyu-force", 200);
        set_skill("zuiyue-strike", 200);
        set_skill("piaoyu-steps", 200);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        set("attitude", "friendly");
        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(__DIR__"obj/zichou")->wear();
}

int accept_kill(object me)
{
	object *ob;

	ob = filter_array(all_inventory(environment())-({this_object()}),(: $1->query("class") == "rain" :) );

	if(sizeof(ob))
		ob->kill_ob(me);

	return 1;
}
