#include <ansi.h>
inherit NPC;

void create()
{
        set_name("年轻人", ({ "nianqing ren" , "ren" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long", "这是一个落魄的书生。\n");

	set_skill("unarmed",10);
	set_skill("dodge",30);

	set("combat_exp",6000);
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
