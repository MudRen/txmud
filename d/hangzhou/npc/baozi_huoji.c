// baozi_huoji.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("小伙计", ({ "huo ji" }) );
	set("title","杭州包子铺");
        set("gender", "男性" );
        set("age", 26);
	set("sell_all_day",1);
        set("long","这是一位杭州包子铺的小伙计。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/baozi" : 50,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
