// Room: /d/path4/hwc23.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc24",
  "northeast" : __DIR__"hwc22",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
