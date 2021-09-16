// Room: /d/path5/na04.c

inherit ROOM;

void create()
{
	set("short", "丛林小路");
	set("long", @LONG
你走在一条丛林间的小路上，脚下不时发出吱吱的声响。两
旁的灌木丛生，随风摇拽，似乎发出一种不祥的信号。你小心溢
溢，洞察可以发生的一切。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"na03",
  "east" : __DIR__"na05",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
