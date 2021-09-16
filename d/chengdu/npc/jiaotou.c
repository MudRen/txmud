// jiaotou.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("孙宝仁", ({"sun bao ren"}));
        set("long", "他是川候武馆的教头，据说以前
曾经在江湖上有一号。\n");

        set("title",HIG"川候武馆--教头"NOR);
        set("gender","男性");
        set("age",32);
	set("str", 55);
	set("force",2000);
        set("max_force",2000);
        set("force_factor",30);

	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);

        set("combat_exp",150000);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("unarmed",150);
	set_skill("axe",100);

        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"axe")->wield();
}
