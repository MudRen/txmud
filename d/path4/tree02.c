// Room: /d/path4/tree02.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tree01",
  "east" : __DIR__"tree03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
