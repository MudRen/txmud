// Room: /d/changan/ch-ft1.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这条大路是由长安通往奉天官道。由于连着京师与北方重镇
奉天，所以格外繁华，路上人来人往。挑担子的、行商的、赶着
大车的马夫，络绎不绝，路边还有一些小商贩在叫卖，非常热闹。
不时还有两三骑快马边飞驰而过，扬起一路尘埃。往南不远就是
长安城的北门了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"out_changan_n",
  "north" : "/d/path1/cc_tch1",
]));
	set("outdoors", "chan-ft");

	setup();
	replace_program(ROOM);
}
