// Room: /d/path4/hed05.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed06",
  "northeast" : __DIR__"hed04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
