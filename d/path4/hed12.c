// Room: /d/path4/hed12.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"hed13",
  "northeast" : __DIR__"hed11",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
