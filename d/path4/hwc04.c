// Room: /d/path4/hwc04.c

inherit ROOM;

void create()
{
	set("short", "�ɷ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc05",
  "east" : __DIR__"hwc03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
