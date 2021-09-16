// Room: /d/path3/cross7.c

inherit ROOM;

void create()
{
	set("short", "山脚小路");
	set("long", @LONG
这里是位于马封山脚下的一条小路，风一吹过，山上树影晃
动，似乎埋伏着人马。你还是小心行事的好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cross6",
  "east" : __DIR__"cross8",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
