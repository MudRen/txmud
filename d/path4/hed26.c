// Room: /d/path4/hed26.c

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed27",
  "east" : __DIR__"hed25",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
