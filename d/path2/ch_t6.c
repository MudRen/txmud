// Room: /d/path2/ch_t6.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土大道，道路两旁是一道道树林形成的防风墙。
轻风拂过，树叶沙沙做响。你向远处望去，一片片高粱地望不到
边，看来又是一个丰收年。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t5",
  "west" : __DIR__"ch_t7",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
