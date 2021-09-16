#include <ansi.h>
inherit NPC;

void create()
{
        set_name("知府大人", ({ "da ren"}) );
        set("gender", "男性" );
        set("title",HIR"公正廉明"NOR);
        set("age", 52);
        set("long", "知府大人的来历谁也不知道。\n");

	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
        set("combat_exp", 150000);
        set("max_force", 2400);
        set("force", 2400);
        set("force_factor", 190);

        set_skill("dodge",300);
        set_skill("parry",300);
        set_skill("unarmed",300);
        set_skill("force",300);
        set_skill("literate",300);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

