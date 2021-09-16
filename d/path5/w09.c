// Room: /d/path5/w09.c

inherit ROOM;

void create()
{
	set("short", "高原小路");
	set("long", @LONG
这是一条荒凉的高原小路，路面有些倾斜。路的两边都是半
人高的杂草，还有一些不知名的野花。你走到这里，觉得有些危
险，不由得加快了脚步。东面不时传来流水的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"w08",
  "westup" : __DIR__"w10",
]));

        set("outdoors", "path5");
//        set("cannot_build_home", 1);
	setup();
	replace_program(ROOM);
}
