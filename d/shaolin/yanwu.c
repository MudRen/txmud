// Room: /d/shaolin/yanwu.c

inherit ROOM;

void create()
{
	set("short", "演武场");
	set("long", @LONG
这里是少林寺的演武场，是每天演练少林大阵罗汉阵的地方，
所以演武场建在这里也是有道理的。演武场是四周挂着写有“少
林”二字的杏黄旗，广场中间地面上竟然的很多深深的脚印，可
见少林阵法的严谨。从这里向东和向西都是过道，向北是天王殿。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tianwang",
  "east" : __DIR__"rroad5",
  "west" : __DIR__"lroad5",
]));
        set("objects", ([
        __DIR__"npc/cleaner" : 1,
]));


	setup();
	replace_program(ROOM);
}
