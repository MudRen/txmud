// Room: /open/dt/yuanwaifu.c

inherit ROOM;

void create()
{
	set("short", "Ա�⸮");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu6",
]));

	setup();
	replace_program(ROOM);
}
