// Room: /d/path4/hed22.c

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed23",
  "north" : __DIR__"hed21",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
