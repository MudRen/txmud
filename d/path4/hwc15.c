// Room: /d/path4/hwc15.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hwc16",
  "southeast" : __DIR__"hwc14",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
