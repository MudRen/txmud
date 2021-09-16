// Room: /wiz/louth/c/chome2.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是陆府的后院，看起来倒是非常讲究，两旁各有两个大
花坛，花坛里开着各色花朵，石子铺就的小路穿行其间。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chome1",
]));

	setup();
	replace_program(ROOM);
}
