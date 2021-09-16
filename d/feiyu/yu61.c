// Room: /u/w/wangs/a/yu61.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾
缭绕，不觉心胸大快。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"yu62",
  "westdown" : __DIR__"yu60",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
