#include <ansi.h>
inherit NPC;

void create()
{
        set_name("雪雨儿", ({ "xueyu er","er","xueyu"}) );
        set("title",CYN"思念念"NOR);
        set("gender", "女性" );
        set("age", 22);
        set("long", "她是一个貌美如花的女孩。\n");
        set("combat_exp", 14000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
