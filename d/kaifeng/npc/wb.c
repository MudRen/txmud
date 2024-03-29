// /d/kaifeng/npc/wb.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("王镖师", ({ "wang biaoshi" , "biaoshi" , "wang" }) );
        set("gender", "男性" );
        set("age", 37);
        set("long", "王镖师在镖局已经很多年了。\n");

	set("max_kee",1000);
	set("max_gin",1000);
	set("max_sen",1000);
        set("combat_exp", 400000);
        set("int", 30);
        set("force", 1900);
        set("max_force", 1900);
        set("force_factor", 20);

        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("unarmed",100);
        set_skill("force",230);
        set_skill("sword",90);

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
