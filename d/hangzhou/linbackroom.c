// Room: /d/hangzhou/linbackroom.c

inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
这是一间小小的花厅，陈设很是简单，一个茶几，上面还有
一局未了的残局，旁边摆了两张石凳。四周挂了几盏走马灯。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"linpath4",
  "west" : __DIR__"linbookroom",
  "north" : __DIR__"linpath3",
]));

	setup();
	replace_program(ROOM);
}
