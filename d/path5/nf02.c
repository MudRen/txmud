// Room: /d/path5/nf02.c

inherit ROOM;

void create()
{
	set("short", "百花林");
	set("long", @LONG
这是一遍长满了各种花草的树林，红的紫的各式各样的花都
有，很多你都叫不出名字来。风一吹过，带来阵阵花香。忽然你
觉得鼻中有些痒，忍不住打了个喷嚏，原来是花粉在做怪。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nf01",
  "east" : __DIR__"nf03",
]));
        set("outdoors", "path5");
        set("altitude", 300);
	setup();
	replace_program(ROOM);
}
