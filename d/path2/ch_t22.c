// Room: /d/path2/ch_t22.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路的两边稀疏地长着一些植物，看起来
这里很少有人经过，显得十分荒凉。由此向北就是安西口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ch_t21",
  "southwest" : __DIR__"ch_t23",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
