#include <ansi.h>
inherit NPC;

void create()
{
        set_name("缃雨儿", ({ "xiangyu er","er","xiangyu"}) );
        set("title",YEL"小雨点"NOR);
        set("gender", "女性" );
        set("age", 22);
        set("long", "她是一个身材娇小的女孩。\n");
        set("combat_exp", 10000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
