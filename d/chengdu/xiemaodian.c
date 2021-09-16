// Room: /wiz/louth/c/xiemaodian.c

inherit ROOM;

void create()
{
	set("short", "鞋帽店");
	set("long", @LONG
这里是成都的二麻鞋店。这里都有的麻柳鞋垫，是专门垫于
鞋内的刺绣实用品。鞋垫内容丰富，图案色彩多样。许多来到成
都的异客都要到这里来买一双麻柳鞋垫。北面是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jguanlu1",
]));
        set("objects",([
        __DIR__"npc/zhangboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
