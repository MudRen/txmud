// Room: /d/path4/hwc24.c

inherit ROOM;

void create()
{
	set("short", "�ּ�յ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hwc25",
  "northeast" : __DIR__"hwc23",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
