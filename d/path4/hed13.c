// Room: /d/path4/hed13.c

inherit ROOM;

void create()
{
	set("short", "��ˮ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tree05",
  "east" : __DIR__"hed12",
  "south" : __DIR__"hed14",
  "north" : __DIR__"hl06",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
