// Room: /d/path4/tree01.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"cd11",
  "east" : __DIR__"tree02",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
