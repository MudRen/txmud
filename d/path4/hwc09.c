// Room: /d/path4/hwc09.c

inherit ROOM;

void create()
{
	set("short", "˿����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"hwc10",
  "south" : __DIR__"hl01",
  "northeast" : __DIR__"hwc08",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
