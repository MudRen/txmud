// Room: /d/path4/hed09.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed10",
  "east" : __DIR__"mznw",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
