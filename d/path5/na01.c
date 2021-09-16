// Room: /d/path5/na01.c

inherit ROOM;

void create()
{
	set("short", "丛林小路");
	set("long", @LONG
你走在一条丛林间的小路上，脚下不时发出吱吱的声响。两
旁的灌木荆棘遍布，偶有些红红绿绿的花穿插其间。南面不远就
是南坪镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanping",
  "north" : __DIR__"na02",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
