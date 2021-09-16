// Room: /d/hangzhou/hotell2.c

inherit ROOM;

void create()
{
	set("short", "梨园二楼");
	set("long", @LONG
这里是梨园酒楼的二楼雅座，和楼下大厅的喧扰相比这里清
净了许多，装饰也精致了许多，就连桌上的茶碗也是真正的景德
镇烧磁。城里的有钱人常常在这里宴请贵宾或举行庆典。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"hotel",
]));

	setup();
	replace_program(ROOM);
}
