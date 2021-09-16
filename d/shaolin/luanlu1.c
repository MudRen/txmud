// Room: /d/shaolin/luanlu1.c

inherit ROOM;

void create()
{
	set("short", "乱石小径");
	set("long", @LONG
这里是一片荒凉的乱石岗，显见很少有人来，一条小径盘绕
其中，远处是一所宏大的寺庙，偶尔随风传来隐约的钟声。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"houshan2",
  "north" : __DIR__"luanlu2",
]));

	setup();
	replace_program(ROOM);
}
