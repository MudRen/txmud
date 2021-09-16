// Room: /d/path5/kch56.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，路上的行人车马来来往往。路侧树林边
摆满了各种小摊，卖什么的都有，十分热闹。你小心翼翼地与他
们擦肩而过，可别被人偷了什么。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/chengdu/out_chengdu_n",
  "north" : __DIR__"kch55",
]));

	set("cannot_build_home", 1);
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
