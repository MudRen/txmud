// Room: /wiz/louth/a/yaxinroom.c

inherit ROOM;

void create()
{
	set("short", "��ܰ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road6",
  "north" : __DIR__"neishi",
]));

	setup();
	replace_program(ROOM);
}
