#include <ansi.h>
inherit NPC;

void create()
{
        set_name("凝雨儿", ({ "ningyu er","er","ningyu"}) );
        set("title",WHT"小乖乖"NOR);
        set("gender", "女性" );
        set("age", 18);
        set("long", "她整天笑嘻嘻的，一副无忧无虑的样子。\n");
        set("combat_exp", 500);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
