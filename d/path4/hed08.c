// Room: /d/path4/hed08.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mzhe",
  "northeast" : __DIR__"hed07",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
