// Room: /d/path4/hwc34.c

inherit ROOM;

void create()
{
	set("short", "���йٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/chengdu/out_chengdu_n",
  "north" : __DIR__"hwc33",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}