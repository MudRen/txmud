// puren1.c
// by dicky

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("仆人", ({ "pu ren", "puren","ren" }) );
	set("gender", "男性" );
	set("age", 25);
	set("int", 28);
	set("long","\n这是个仆人打扮的年青人，两眼乱转，四处看个不停,好象害怕什么。\n");
	set("attitude", "peaceful");
        set("combat_exp",80000+random(20000));

        set("max_kee",800);
        set("max_gin",800);
        set("max_sen",800);

        set_skill("unarmed",80);
        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("force",80);
        set_skill("sword",80);	  


	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
