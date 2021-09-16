// Room: /d/path2/ch_t11.c

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
这是一条黄土大道，道路两旁是一片片树林，轻风拂过，树
叶沙沙做响。你向远处望去，一片片高粱地望不到边，一些农民
正在地里耕作。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_t10",
  "south" : __DIR__"ch_t12",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
