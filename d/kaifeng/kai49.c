// Room: /u/w/wangs/b/kai49.c

inherit ROOM;

void create()
{
	set("short", "珠宝店");
	set("long", @LONG
这条路上竟然会有珠宝店，你带着一脸疑惑的表情走了进来。
店主人把你上上下下打量了一遍，堆起满脸的谄笑迎了上来，点
头哈腰的带你去选购首饰。你从柜台上的檀木匣中随手拈起一串
珍珠项链来，迎着光一看，不禁哑然失笑，原来这里卖的都是便
宜的假货。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kai61",
]));
        set("objects",([
        __DIR__"npc/qianlaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
