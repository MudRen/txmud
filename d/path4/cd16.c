// Room: /d/path4/cd16.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"cd15",
  "south" : __DIR__"cd17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
