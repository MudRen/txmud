// ren.c

#include <ansi.h>

inherit F_DEALER;

void create()
{
	set_name("任一力", ({ "ren yili","ren" }) );
	set("title","饺子大王");

        set("gender", "男性" );
        set("age", 42);
	set("sell_all_day",1);

	set("long","这是一位满面红光的中年人。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
		__DIR__"obj/jiaozi" : -1,
        ]) );
        setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
