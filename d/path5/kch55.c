// Room: /d/path5/kch55.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，道上过往的行人身着各异，不少穿着你
都没有见过。有些小贩拿着你也叫不出名的东西向你走来，你见
状急闪，还是以后有机会再说吧。南面不远就是成都北门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kch56",
  "north" : __DIR__"kch54",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
