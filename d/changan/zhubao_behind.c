// Room: /d/changan/zhubao_behind.c

inherit ROOM;

void create()
{
	set("short", "后房");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zhubao_room",
  "down" : __DIR__"didao/entry",
]));

	setup();
	replace_program(ROOM);
}
