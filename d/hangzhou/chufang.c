// Room: /d/hangzhou/chufang.c

inherit ROOM;

void create()
{
	set("short", "后厨");
	set("long", @LONG
这里是梨园酒楼的后厨房，这里宽敞明亮对面是一排灶台，
左面两个巨大的水缸边上是一溜大木桌，右面的架子上堆满了用
过的碗和盘子。门口挂着一块木牌子(pai)。
LONG
	);

        set(SAFE_ENV,1);
	set("exits",([
	"west" : __DIR__"hotel",
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
