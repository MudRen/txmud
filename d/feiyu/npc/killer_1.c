inherit NPC;
#include <ansi.h>
void create()
{
        set_name("������", ({ "su yaoyao","su","yaoyao" }) );
        set("gender", "Ů��" );
        set("age", 25);
        set("title",  HIR "����--�Ĵ�ɱ��"NOR);;
        set("per", 30);
        set("attitude", "peaceful");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("max_force", 3000);
        set("force", 3000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);

        set("long",     "������Ĵ�ɱ��֮һ��\n");

        set("combat_exp", 1500000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("jieqing-sword", 220);
        set_skill("suiyu-force", 200);
        set_skill("zuiyue-strike", 200);
        set_skill("piaoyu-steps", 200);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        setup();

        carry_object(__DIR__"obj/shasword")->wield();
        carry_object(__DIR__"obj/shacloth")->wear();
}


