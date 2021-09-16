// Room: /u/w/wangs/b/kai141.c

inherit ROOM;

void create()
{
	set("short", "开封东街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。路上行人熙熙攘攘，
很多卖冰糖葫芦的、风味小吃的小商贩们沿街叫卖，走在这条街
上，你深切感受到了俗世的繁华与喧嚣。路南边是一家沐浴斋，
北边则是闻名遐迩的天马镖局，再向西不远就是中心街了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai143",
  "north" : __DIR__"kai142",
  "west" : __DIR__"kai138",
  "east" : __DIR__"kai144",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
