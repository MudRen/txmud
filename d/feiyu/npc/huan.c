#include <ansi.h>
inherit NPC;

void create()
{
        set_name("浣雨儿", ({ "huanyu er","er","huanyu"}) );
        set("title",HIW"忧忧郁"NOR);
        set("gender", "女性" );
        set("age", 21);
        set("long", "她长的楚楚动人，谁见了她都会很喜欢。\n");
        set("combat_exp", 6000);
        set("per", 30);
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
