// Room: /d/hangzhou/forest1.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这里是杭州城外的一片树林，这里的树木生长的分外的茂盛
，巨大的枝杈延伸开来，遮天蔽日，只有一丝丝的阳光从缝隙中
泄漏下来。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"forest2",
  "east" : __DIR__"forest3",
  "north" : __DIR__"banboo1",
]));

	setup();
	replace_program(ROOM);
}
