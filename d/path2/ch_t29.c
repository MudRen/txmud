// Room: /d/path2/ch_t29.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路的两边稀疏地长着一些杂草，看起来
这里很少有人经过，显得十分荒凉。几个小孩在离路不远草地上
扒来扒去，不知在找些什么。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_t28",
  "west" : __DIR__"ch_t30",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
