// Room: /u/w/wangs/a/yu69.c

inherit ROOM;

void create()
{
	set("short", "悬崖底");
	set("long", @LONG
你的面前是一座笔直的山峰，高若千丈，峰顶在云雾中
隐约可见，山峰光秃秃的，更无置手足处，只能顺着崖壁前
后走动。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yu72",
  "north" : __DIR__"yu70",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
