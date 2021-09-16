// Room: /d/shaolin/e_court.c

inherit ROOM;

void create()
{
	set("short", "东跨院");
	set("long", @LONG
这里是少林寺的东跨院，院中一颗高大的柏树，据说是达摩
老祖在建少林寺时就种下了，翳阴遮满了整个院子，即使是盛夏
也丝毫不觉得炎热。从这里向北是兵器室，向东是休息室，向西
则是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bingqiku",
  "east" : __DIR__"sleeproom",
  "west" : __DIR__"rroad3",
]));
	set("valid_startroom", 1);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
