// Room: /wiz/louth/c/shangzhan.c

inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jguanlu7",
]));

	setup();
	replace_program(ROOM);
}
