// Room: /d/path4/cd08.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd07",
  "east" : __DIR__"cd09",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
