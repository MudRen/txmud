// zong1.c

#include <ansi.h>

inherit QUESTER;

int ask_quest(object me)
{
	string clas;

	if(!me
	|| !(clas = me->query("class"))
	|| ( clas != query("class")))
		return 0;

	me->delete("patroling");

	return ::ask_quest(me);
}

void create()
{
        set_name("����", ({ "qing wu" }) );
        set("title",HIW"�����ܹ�"NOR);
        set("gender", "Ů��" );
        set("age", 32);
	set("class","rain");
        set("long", "����Ķ����ܹܴ���û��Ц����\n");
        set("combat_exp", 2200000);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",200);
        set("per", 30);
        set("str", 30); 

        set_skill("unarmed",250);
        set_skill("force",250);
        set_skill("dodge",250);
        set_skill("parry",250);
        set_skill("sword",250);
        set_skill("jieqing-sword", 250);
        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("piaoyu-steps", 250);
 
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

