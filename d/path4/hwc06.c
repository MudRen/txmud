// Room: /d/path4/hwc06.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc07",
  "northeast" : __DIR__"hwc05",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}