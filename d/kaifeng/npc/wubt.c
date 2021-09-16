// wubt.c

#include <ansi.h>
inherit NPC;
inherit TEACH_NPC;

void create()
{
        set_name("吴总镖头", ({ "wu biaotou" , "biaotou" , "wu" }) );
        set("title",HIW"天马镖局"NOR);
        set("nicknake",HIR"飞舞行天"NOR);
        set("gender", "男性" );
        set("age", 42);
        set("long", "吴总镖头一身硬功罕遇对手。\n");

	set(NO_KILL, 1);

        set("combat_exp", 600000);
        set("str", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 40);

	set("max_kee",1000);
	set("max_gin",1300);
	set("max_sen",1300);

        set_skill("dodge",120);
	set_skill("parry",120);
        set_skill("unarmed",90);
        set_skill("force",200);
	set_skill("sword",90);
	set_skill("spells",200);
	set_skill("magic",200);

	set_valid_skill( ({ "spells","magic" }) );

        setup();
        carry_object(WEAPON_DIR"sword")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int is_apprentice_of(object ob)
{ return 1; }
