// Room: /d/path1/cc_tch4.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条连着京师与北方重镇的官道，所以格外繁华，路上
人来人往。挑担子的、行商的、赶着大车的马夫，络绎不绝，路
边还有一些小商贩在叫卖，非常热闹。不时还有两三骑快马边飞
驰而过，扬起一路尘埃。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cc_tch3",
  "north" : __DIR__"cc_tch5",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/huntun_seller" : 1,
]));

	setup();
	replace_program(ROOM);
}
