// Room: /d/shaolin/yongdao4.c

inherit ROOM;

void create()
{
	set("short", "青石甬道");
	set("long", @LONG
这里是少林寺的一条青石甬道，因为在后院，又是地处重地，
只有少数辈份高的僧人才许来这里。你走这里，听着树林里的鸟
叫，看着这美景，混然进入了忘我的境界。从这里向北是方丈的
禅房，向南是青石甬道，东北方和西北方是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"lroad4",
  "northeast" : __DIR__"rroad4",
  "south" : __DIR__"yongdao3",
  "north" : __DIR__"fangzhang1",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
