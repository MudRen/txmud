// Room: /d/path4/hwc17.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc18",
  "southeast" : __DIR__"hwc16",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
