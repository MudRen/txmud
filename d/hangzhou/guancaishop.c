// Room: /d/hangzhou/guancaishop.c

inherit ROOM;

void create()
{
	set("short", "棺材铺");
	set("long", @LONG
你正站在一间棺材铺的大门口，门里面摆满了各式各样的棺
材，旁边还摆着一些纸钱，供香之类的东西，房梁上还挂着几张
招魂幡在烛光的映照下轻轻摇动。整个房间充满了阴森的气息。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rockroad2",
]));

	setup();
	replace_program(ROOM);
}
