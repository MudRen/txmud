// Room: /d/path1/zjz11.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条黄土小路，路的两边是一片片的稻田，几个农户正
在田里忙活儿着，还有几只老牛在田边吃着草。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zjz10",
  "east" : __DIR__"zjz12",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
