// Room: /d/path5/kch39.c

inherit ROOM;

void create()
{
	set("short", "盘曲");
	set("long", @LONG
这里是盘曲，由此再上西北就上青城山了。路边一堆白花花
的像是什么动物的骸骨。东南方向不远就是成都了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"kch40",
  "westup" : __DIR__"kch38",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
