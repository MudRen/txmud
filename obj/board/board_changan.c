// board_changan.c

inherit BOARD;

void create()
{
	set_name("一般用途留言板", ({ "board" }) );
	set("long","这是一个供人留言记事的留言板。" );
	setup();
}
