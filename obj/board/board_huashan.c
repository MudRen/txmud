// board_huashan.c

#include <ansi.h>

inherit BOARD;

void create()
{
	set_name("华山论剑", ({ "board" }) );
	set("long","这是一个供人留言记事的留言板。" );
	setup();
}
