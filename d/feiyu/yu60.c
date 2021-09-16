// Room: /u/w/wangs/a/yu60.c

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
  "westdown" : __DIR__"yu59",
  "eastup" : __DIR__"yu61",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
