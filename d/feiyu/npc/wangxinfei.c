#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "wang xinfei","wang","xinfei"}) );
        set("gender", "Ů��" );
        set("age", 32);
        set("long", "����һλ����ĺ���֮�㡣\n");
        set("combat_exp", 600000);
        set("per", 30);
        set("int", 30); 
        create_family("����", 3, "����");

        set_skill("unarmed",170);
        set_skill("force",170);
        set_skill("dodge",170);
        set_skill("parry",170);
        set_skill("sword",170);
        set_skill("jieqing-sword", 170);
        set_skill("suiyu-force", 170);
        set_skill("zuiyue-strike", 170);
        set_skill("piaoyu-steps", 170);
 
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
