#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ŵ���", ({ "rumen dizi" , "dizi"}) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long", "����һλ���Ų��õ��µ��ӡ�\n");
        set("combat_exp", 20000);
        set("per", 30);
        set("attitude", "friendly");
        set("max_force",300);
        set("force",300);
        set("force_factor",50);
        create_family("����", 9, "����");

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

