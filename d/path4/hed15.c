// Room: /d/path4/hed15.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed16",
  "north" : __DIR__"hed14",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
