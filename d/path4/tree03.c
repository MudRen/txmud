// Room: /d/path4/tree03.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree02",
  "northeast" : __DIR__"tree04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
