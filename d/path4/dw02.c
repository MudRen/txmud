// Room: /d/path4/dw02.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dw03",
  "east" : __DIR__"dw01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}