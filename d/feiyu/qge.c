// Room: /wiz/louth/a/qge.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road3",
]));

	setup();
	replace_program(ROOM);
}
