#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ɮ��", ({ "seng ren"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "һ�������µ�ɮ�ˡ�\n");

        set("combat_exp", 100000);
        set("max_force", 2100);
        set("force", 2100);
        set("force_factor", 10);

        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("unarmed",50);
        set_skill("force",180);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
