// Room: /wiz/louth/k/kai31.c

inherit ROOM;

void create()
{
	set("short", "��ԡ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kai143",
]));

	setup();
	replace_program(ROOM);
}
