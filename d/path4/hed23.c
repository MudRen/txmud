// Room: /d/path4/hed23.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed24",
  "north" : __DIR__"hed22",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
