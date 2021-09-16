// Room: /d/path5/nf03.c

inherit ROOM;

void create()
{
	set("short", "百花林");
	set("long", @LONG
这是一遍长满了各种花草的树林，红的紫的各式各样的花都
有，很多你都叫不出名字来。风一吹过，带来阵阵花香。一群群
蜜蜂在花丛中飞来飞去，样子好像和平时见的不太一样。这种地
方还是小心些好。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nf03",
  "west" : __DIR__"nf02",
  "south" : __DIR__"nf03",
  "north" : __DIR__"nf03",
]));
        set("outdoors", "path5");
        set("altitude", 300);
	setup();
	replace_program(ROOM);
}
