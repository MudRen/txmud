// Room: /d/path4/hwc02.c

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc03",
  "east" : __DIR__"hwc01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
