// Room: /u/w/wangs/b/kai51.c

inherit ROOM;

void create()
{
	set("short", "粮店");
	set("long", @LONG
这是一家很大的粮店，十几个伙计正在把一袋袋大米从马车
上卸下来，这里供应着全城百姓的口粮，所以生意特别的红火，
这里整齐的码放着数百袋大米，其它的都堆放在后面的库房里。
出了门就是山南街了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai50",
]));

        set("objects",([
        __DIR__"npc/ldboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
