// Room: chengxf7.c

inherit ROOM;

void create()
{
        set("short", "书房");
	set("long", @LONG
这里是长安丞相府的书房，一进门你就看到墙上挂着丞相亲
笔画的一幅听琴图，画面干净有致，堪称是一佳作。四壁的书架
上摆满了，各种书籍，桌上放置着文房四宝。从这里向西便是正
厅了。
LONG
	);

        set("exits", ([
  "west" : __DIR__"chengxf6",
]));
        setup();

	replace_program(ROOM);
}