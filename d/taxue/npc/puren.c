// puren.c
// by dicky

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({ "pu ren", "puren","ren" }) );
        set("gender", "����" );
        set("age", 20);
        set("long","���Ǹ����˴��������ˣ�������ת���Ĵ�������ͣ��\n");
        set("attitude", "peaceful");
        set("combat_exp",60000+random(1000));
        
        set("max_kee",400);
        set("max_gin",400);
        set("max_sen",400);

        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("force",60);
        set_skill("sword",60);	  

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
