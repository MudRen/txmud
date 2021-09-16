// Room: /d/hangzhou/linguard.c

inherit ROOM;

void create()
{
	set("short", "家丁室");
	set("long", @LONG
这里是林家家丁住的地方，一个大房间里最显眼的是占据了
半间房子的大通炕，床铺打扫的还算干净，另一边的墙上挂了不
少刀剑武器。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"linneiyuan",
]));

	set("objects",([
	__DIR__"npc/jiading" : 1,
]));

	setup();
	replace_program(ROOM);
}
