// board_tangmen.c

#include <ansi.h>
inherit BOARD;

void create()
{
	set_name(BWHT HIB"唐门鉴"NOR, ({ "board" }) );
	set("long","这是一个供人留言记事的留言板。" );
	setup();
}
