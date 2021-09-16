// Room: /d/hangzhou/zfxiaojie.c

inherit ROOM;

void create()
{
	set("short", "小姐闺房");
	set("long", @LONG
这里是知府独生女儿的闺房，房正中有一张檀木圆桌，上面
放着一盏油灯和几本书，靠墙的地方是小姐的秀床，确实幔帐低
垂。床旁边是一张小小的梳妆台，整个房间看上去十分的雅致。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zfroom",
]));

	setup();
	replace_program(ROOM);
}
