// Room: /wiz/louth/a/rou5.c

inherit ROOM;

void create()
{
	set("short", "小木桥");
	set("long", @LONG
这是一个用原木扎成的小木桥，两边用铁索固定，非常坚固，
桥下的溪水清澈见底。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"rou6",
  "west" : __DIR__"rou1",
]));

	set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
