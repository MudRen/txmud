// Room: /d/path4/cd18.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cd19",
  "north" : __DIR__"cd17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
