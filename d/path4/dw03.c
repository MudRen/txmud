// Room: /d/path4/dw03.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dw04",
  "east" : __DIR__"dw02",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
