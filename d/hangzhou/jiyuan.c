// Room: /d/hangzhou/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "万花楼");
	set("long", @LONG
就像每个房子都有门，每个大城市都会有妓院，这里就是杭
州城里最大的一间，苏杭一向是美人倍出，这里当然也是环肥燕
瘦，应有尽有。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"minan04",
  "east" : __DIR__"jiyuan01",
]));

	setup();
	replace_program(ROOM);
}
