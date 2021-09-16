// Room: /d/shaolin/f_square.c

inherit ROOM;

void create()
{
	set("short", "前院广场");
	set("long", @LONG
这里是少林寺的广场前院，很是开阔，可以看见很多阶台阶
向上延伸着，台阶的尽头依稀是天王殿。广场两边两个巨大的水
缸，里面整满了清水，是以防寺中着火救用的。来来往往的香客
满脸虔诚，如果你置身于其间，也会受到气氛的感染的。从这里
向西是广场的左侧，向东是广场的右侧，北面是台阶，南边是山
门。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"door",
  "north" : __DIR__"taijie",
  "east" : __DIR__"f_square_r",
  "west" : __DIR__"f_square_l",
]));

	set("outdoors", "shaolin");

	setup();
	load_board("board_shaolin");
	replace_program(ROOM);
}
