// board_wiz.c

inherit BOARD;

void create()
{
	set_name("巫师留言版", ({ "board" }) );
	set("long","这是一个供巫师留言记事的留言板。" );
	setup();
}
