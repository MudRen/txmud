// Room: /wiz/louth/c/wwdao3.c

inherit ROOM;

void create()
{
	set("short", "武王道");
	set("long", @LONG
这里是成都西面的武王道。从这里向西走就是成都的西门。
向东走就是著名的武王祠。向北可以走道万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wwdao4",
  "west" : __DIR__"wdoor",
  "east" : __DIR__"wuwangsi",
  "north" : __DIR__"wwdao2",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
