// Room: /d/path4/dw05.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"dw06",
  "southeast" : __DIR__"dw04",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
