// Room: /d/shaolin/f_square_r.c

inherit ROOM;

void create()
{
	set("short", "广场右侧");
	set("long", @LONG
这里是少林寺的广场右侧，是一新入寺的僧人们习武的地方，
地上有许多深深的脚印，是少林弟子们长年在这里练功时留下的，
几个少林弟子，正在演习着师傅所教的罗汉长拳。从这里向西是
广场前院，向东是慈云堂，北面是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"rroad1",
  "east" : __DIR__"ciyuntang",
  "west" : __DIR__"f_square",
]));

	set("objects",([
	__DIR__"npc/juewu" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
