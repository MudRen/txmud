#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "shi bi"}) );
        set("title",YEL"����--˪�������"NOR);
        set("gender", "Ů��" );
        set("age", 22);
	set("class","rain");
        set("long", "�Ĵ�����������ܲ����������\n");
        set("combat_exp", 2200000);
        set("str",120);
        set("per", 30);
        set("attitude", "friendly");
        set("max_force",3000);
        set("force",3000);
        set("force_factor",200);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);

        set_skill("dodge",250);
        set_skill("sword",250);
        set_skill("parry",250);
        set_skill("jieqing-sword", 250);
        set_skill("suiyu-force", 250);
        set_skill("zuiyue-strike", 250);
        set_skill("piaoyu-steps", 250);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        set_skill("force",230);

        setup();
        carry_object(__DIR__"obj/feiyujian")->wield();
        carry_object(__DIR__"obj/feiyushan")->wear();
}
