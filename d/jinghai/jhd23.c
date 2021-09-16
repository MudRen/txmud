// Room: /d/jinghai/jhd23.c

inherit ROOM;

void create()
{
	set("short", "山庄后院");
	set("long", @LONG
这里是靖海府的后院，比起前院来这里安静了很多，因为南
面不远处就是靖海派的议事厅了。院子中间是一个小小水池，池
中一座假山中喷出清澈的泉水，周围墙边种植了几从修竹。往北
去就是闻名遐迩的靖海山庄厨房了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jhd25",
  "east" : __DIR__"jhd20",
  "south" : __DIR__"jhd26",
  "west" : __DIR__"jhd24",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
