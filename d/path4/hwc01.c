// Room: /d/path4/hwc01.c

inherit ROOM;

void create()
{
	set("short", "ʯ����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hwc02",
  "east" : "/d/hangzhou/out_hangzhou_w",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
