// Room: /d/path4/dw01.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dw02",
  "east" : "/d/dali/out_dali_w",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
