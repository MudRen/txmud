// Room: /d/path4/tree05.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tree04",
  "east" : __DIR__"hed13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
