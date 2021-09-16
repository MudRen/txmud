// Room: /wiz/louth/a/rdi5.c

inherit ROOM;

void create()
{
	set("short", "地洞");
	set("long", @LONG
这是一条狭小漆黑的地洞，周围清冷的石壁上挂着水珠，上
面有几个小黑洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"shanlu7",
  "east" : __DIR__"rdi4",
]));
	setup();
	replace_program(ROOM);
}
