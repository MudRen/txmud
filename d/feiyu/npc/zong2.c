#include <ansi.h>
inherit NPC;
string ask_me(object me);

void create()
{
        set_name("绿绫", ({ "lv ling","zong guan","ling"}) );
        set("title",HIW"绯雨阁副总管"NOR);
        set("gender", "女性" );
        set("age", 30);
	set("class","rain");
        set("long", "绯雨阁的二大总管从来没有笑脸。\n");
        set("combat_exp", 1800000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",150);
        set("per", 30);
        set("str", 30); 

        set_skill("unarmed",230);
        set_skill("force",230);
        set_skill("dodge",230);
        set_skill("parry",230);
        set_skill("sword",230);
        set_skill("jieqing-sword", 230);
        set_skill("suiyu-force", 230);
        set_skill("zuiyue-strike", 230);
        set_skill("piaoyu-steps", 230);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        set("attitude", "friendly");
        set("inquiry", ([
		"树林" : (: ask_me :),
//                  "封云茵":(:ask_me1:),   
]) );
        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}


string ask_me(object me)
{
	if (me->query("class") != "rain")
		return 0;

        if (!me->query_temp("louth_shengji1_shulin2"))
                return "树林？绯雨阁里没有。梅花林到是有一片。\n";

	me->delete_temp("louth_shengji1_shulin2");
	me->set_temp("louth_shengji1_shulin3",1);
	return ("进入树林后大概按照南、西、南、东、东的顺序走，就快要走出去了。\n");
}
