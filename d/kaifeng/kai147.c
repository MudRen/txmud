// Room: /u/w/wangs/b/kai147.c

inherit ROOM;

void create()
{
	set("short", "开封东街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。路上行人熙熙攘攘，
很多卖冰糖葫芦的、风味小吃的小商贩们沿街叫卖，走在这条街
上，你深切感受到了俗世的繁华与喧嚣。路北通向夷林东路，往
南是前松街，再向东不远就是开封东门了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai156",
  "west" : __DIR__"kai144",
  "northeast" : __DIR__"kai135",
  "east" : __DIR__"edoor",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
