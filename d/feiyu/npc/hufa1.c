#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "zhang suifeng","zhang","suifeng"}) );
        set("title",HIW"����--�Ĵ���"NOR);
        set("gender", "Ů��" );
        set("age", 26);
	set("class","rain");
        set("long", "�����Ľ�����ר�Ÿ�������������Ĵ�����\n");
        set("combat_exp", 1800000);
        set("str",100);
        set("per", 30);
        set("attitude", "friendly");
        set("max_force",3000);
        set("force",3000);
        set("force_factor",250);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);

        set_skill("dodge",230);
        set_skill("sword",230);
        set_skill("parry",230);
        set_skill("jieqing-sword", 230);
        set_skill("suiyu-force", 230);
        set_skill("zuiyue-strike", 230);
        set_skill("piaoyu-steps", 230);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");
        set_skill("force",230);

        setup();
        carry_object(__DIR__"obj/feiyujian")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

