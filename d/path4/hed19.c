// Room: /d/path4/hed19.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed20",
  "northeast" : __DIR__"hed18",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
