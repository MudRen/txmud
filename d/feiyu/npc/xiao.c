#include <ansi.h>
inherit NPC;

void create()
{
        set_name("萧雨儿", ({ "xiaoyu er","er","xiaoyu"}) );
        set("title",CYN"静悄悄"NOR);
        set("gender", "女性" );
        set("age", 19);
        set("long", "她特别喜欢一个人发呆，是个文静的女孩。\n");
        set("combat_exp", 16000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
