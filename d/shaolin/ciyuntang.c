// Room: /d/shaolin/ciyuntang.c

inherit ROOM;

void create()
{
	set("short", "慈云堂");
	set("long", @LONG
这里是少林寺的慈云堂，是接受剃度的地方。一些附近的善
男信女都将子弟送到这里来，学习佛法，当然有的可以一直留在
寺里，有的则没几年便留发还俗了。一个老僧正闭目颂经。从这
里向东是碑林，向西是广场右侧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beilin3",
  "west" : __DIR__"f_square_r",
]));
	set(SAFE_ENV,1);
	set("objects",([
	__DIR__"npc/tidu_seng" : 1,
]));

	setup();
	replace_program(ROOM);
}
