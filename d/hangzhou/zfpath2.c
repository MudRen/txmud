// Room: /d/hangzhou/zfpath2.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是通往监牢的小路，平常除了送饭的老衙役，很少有人经
过这里。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zfpath1",
  "east" : __DIR__"zfjianlao",
]));

	setup();
	replace_program(ROOM);
}
