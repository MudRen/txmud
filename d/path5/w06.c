// Room: /d/path5/w06.c

inherit ROOM;

void create()
{
	set("short", "高原小路");
	set("long", @LONG
这是一条荒凉的高原小路，路面有些倾斜。路的两边都是半
人高的杂草，还有一些不知名的野花。你走到这里，觉得有些危
险，不由得加快了脚步。西面不时传来流水的声音。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w07",
  "northeast" : __DIR__"w05",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
