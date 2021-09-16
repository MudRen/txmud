// Room: /u/w/wangs/a/yu31.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是绯雨阁中的一条走廊，彩梁画栋，连顶棚也用彩漆
绘满了各种漂亮的图形，更令人叹为观止的是每幅精美的雕
画都诉说了一个或美丽或凄婉的故事。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"yu32",
  "east" : __DIR__"yu22",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
