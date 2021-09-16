// Room: /d/path5/e05.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是一条林中小路，你走在茂密的树林，稀巯的光线随着树
叶的摇摆一闪一闪，依稀可以看到路的痕迹。江南的林中长满了
各种灌木植物，小心不要伤着自己哦。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"e04",
  "east" : __DIR__"e06",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
