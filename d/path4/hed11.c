// Room: /d/path4/hed11.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed12",
  "east" : __DIR__"hed10",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
