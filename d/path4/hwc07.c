// Room: /d/path4/hwc07.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc08",
  "northeast" : __DIR__"hwc06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
