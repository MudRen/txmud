#include <ansi.h>
inherit NPC;

void create()
{
        set_name("小意", ({ "xiao yi"}) );
        set("nickname",WHT"醉舞花魂"NOR);
        set("title",MAG"神秘紫衣女子"NOR);
        set("gender", "女性" );
        set("age", 25);
        set("long", "她美的出奇，美的无法用言语形容。\n");
        set("combat_exp", 10);
        set("per", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
                "小意静静的期待着一个人对她说,说她是那个人今生唯一的传说...。。。\n",
                "小意在等待一个人对她说,说的内容只有他们两个人才知道...。。。\n",
        }) );
        set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

