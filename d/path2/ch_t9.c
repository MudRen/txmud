// Room: /d/path2/ch_t9.c

inherit ROOM;

void create()
{
	set("short", "林荫路");
	set("long", @LONG
你走在林荫道上，抬头看去，绿树蓝天，景色迷人。忽然林
中传来一种奇怪的叫声，不知是什么东西，你吓了一跳，急忙加
快了脚步。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t8",
  "northwest" : __DIR__"ch_t13",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
