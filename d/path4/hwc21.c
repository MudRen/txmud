// Room: /d/path4/hwc21.c

inherit ROOM;

void create()
{
	set("short", "�������ζɿ��ϰ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hwc20",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
