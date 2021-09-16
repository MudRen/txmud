// Room: /wiz/louth/a/rou6.c

inherit ROOM;

void create()
{
	set("short", "木屋");
	set("long", @LONG
这是一间简陋的小木屋，四处收拾得干干净净，屋子里没有
什么陈设，只有靠墙的木柜里摆放着几本书。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rou5",
  "north" : __DIR__"rou7",
]));

	setup();
	replace_program(ROOM);
}
