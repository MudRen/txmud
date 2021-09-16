// Room: /d/path5/kch05.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是这是一条崎岖的小路，路面不平不说，还到处是碎的石块。
你走在路上，总感到有什么危险，还是走快些吧，省得节外生枝。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch06",
  "north" : __DIR__"kch04",
]));

        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
