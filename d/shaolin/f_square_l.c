// Room: /d/shaolin/f_square_l.c

inherit ROOM;

void create()
{
	set("short", "广场左侧");
	set("long", @LONG
这里是少林寺的广场左侧，是少林寺俗家弟子们练功的地方，
南边摆着个一些练武用的器械，如石礅什么的和一些木质兵器，
一些俗家弟子，正在这里苦练着。从这里向东是锤谱堂，向西是
前院广场，北面是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lroad1",
  "east" : __DIR__"f_square",
  "west" : __DIR__"zhongputang",
]));

	set("outdoors", "shaolin");
	set("objects", ([
	__DIR__"npc/jueyuan" : 1,
        __DIR__"npc/cleaner" : 1,
]));

	setup();
	replace_program(ROOM);
}
