// Room: /u/w/wangs/a/yu22.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁后院");
	set("long", @LONG
这里是绯雨阁后院。走到这里，花香味更加浓烈了。你
仔细一看，遍地种满了奇异的花草，一群群蜜蜂、蝴蝶在花
丛中飞舞。东西有两条走廊，北面是绯雨阁的大厅。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu37",
  "north" : __DIR__"yu21",
  "west" : __DIR__"yu31",
  "east" : __DIR__"yu23",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
