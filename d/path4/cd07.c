// Room: /d/path4/cd07.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd06",
  "east" : __DIR__"cd08",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
