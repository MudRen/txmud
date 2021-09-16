// Room: /d/shaolin/luanlu5.c

inherit ROOM;

void create()
{
	set("short", "乱石小径");
	set("long", @LONG
这里是一片荒凉的乱石岗，显见很少有人来，一条小径盘绕
其中，远处是一所宏大的寺庙，偶尔随风传来隐约的钟声。北面
是一片小树林。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : __DIR__"luanlu4",
]));

	setup();
	replace_program(ROOM);
}
