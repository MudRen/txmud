// Room: /d/path4/tree04.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tree03",
  "northeast" : __DIR__"tree05",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
