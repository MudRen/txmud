// Room: /d/hangzhou/jiyuan07.c

inherit ROOM;

void create()
{
	set("short", "紫琼房间");
	set("long", @LONG
这是一间什麽也没有的空房间。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiyuan04",
]));

	setup();
	replace_program(ROOM);
}
