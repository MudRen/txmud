// Room: /d/shaolin/zhongputang.c

inherit ROOM;

void create()
{
	set("short", "锤谱堂");
	set("long", @LONG
这里是少林寺的锤谱堂，是招收少林寺俗家弟子的地方，每
当有年青人来这里，这里的师傅都会详细的问清他的情况，再证
实他的品行确实没有什么问题，才会招为少林俗家弟子的。从这
里向西是功德林，向东是前院广场左侧。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"f_square_l",
  "west" : __DIR__"gongde3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
