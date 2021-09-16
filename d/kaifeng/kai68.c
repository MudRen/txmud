// Room: /u/w/wangs/b/kai68.c

inherit ROOM;

void create()
{
	set("short", "开封西街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。路上行人熙熙攘攘，
很多卖冰糖葫芦的、风味小吃的小商贩们沿街叫卖，走在这条街
上，你深切感受到了俗世的繁华与喧嚣。路南边是一家书院，北
边则是闻名遐迩的李记珠宝行，再向东不远就是中心街了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai70",
  "north" : __DIR__"kai69",
  "west" : __DIR__"kai65",
  "east" : __DIR__"kai71",
]));
        set("objects",([
        __DIR__"npc/beggar": 1,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
