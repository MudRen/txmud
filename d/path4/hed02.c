// Room: /d/path4/hed02.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed03",
  "north" : __DIR__"hed01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
