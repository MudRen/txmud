// Room: /d/path5/w01.c

inherit ROOM;

void create()
{
	set("short", "上坡路");
	set("long", @LONG
这是一条略平整些的小路，路面有些倾斜。路的两边都是半
人高的杂草，还有一些不知名的野花。看起来有些荒凉，你不由
得加快了脚步。由此再向西去，地势越来越高了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kch03",
  "westup" : __DIR__"w02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
