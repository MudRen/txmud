// Room: /d/hangzhou/wanghouse.c

inherit ROOM;

void create()
{
	set("short", "王老汉家");
	set("long", @LONG
这是一个不大的院子，四周围着篱笆墙，北墙下支着一张渔
网，旁边的架子上面挂满了鱼虾，院子中央的树阴下有一张石桌
，几个石凳，桌子上还摆个一个酒葫芦。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad1",
]));

	setup();
	replace_program(ROOM);
}
