// Room: /d/path4/hed14.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed15",
  "north" : __DIR__"hed13",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
