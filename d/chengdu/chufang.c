// Room: /d/changan/chufang.c

inherit ROOM;

void create()
{
	set("short", "瑞芙酒楼后厨");
	set("long", @LONG
这里是瑞芙酒楼的后厨房，左手两个巨大的水缸边上是一溜
大木桌，右手的架子上堆满了用过的碗和盘子。门口挂着一块木
牌子(pai)。
LONG
);

        set("no_fight",1);
	set("exits",([
	"east" : __DIR__"furuilou",
]));
	set("item_desc",([
                "pai" : "招收洗(xi)盘子、洗碗的小工。\n",
]));

	set("objects",([
		__DIR__"npc/cooker" : 1,
]));

	setup();
	replace_program(ROOM);
}
