// Room: /wiz/louth/k/kai44.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai38",
]));

	setup();
	replace_program(ROOM);
}
