// Room: /d/changan/selling_room.c

inherit "/std/room/selling_room";

void create()
{
	::create();

	set("short", "百姓交易所");
	set("long", @LONG
这是一处空空荡荡的小房间，迎面一张木桌后面作着一位獐
头鼠目的中年人，爱搭不理的瞟了你一眼。桌子前面立着着一块
大木板(ban)。
LONG
);

	set(SAFE_ENV, 1);
	set("exits", ([
	"west" : __DIR__"sroad8",
]));

	set("item_desc", ([
	"ban" : "
                通告

     百姓可以在这里对自己的私有物品进行
拍卖。每笔交易收取 2 两银子的手续费。叫
卖指令的格式：
    sell 物品 起始价格(单位：白银)

    别人出价过程中如认为合适，可以用命
令 accept 接受出价完成交易。

    如果中途想停止叫卖，用 sell stop 命
令来中止。\n
",
	"木板" : "
                通告

     百姓可以在这里对自己的私有物品进行
拍卖。每笔交易收取 2 两银子的手续费。叫
卖指令的格式：
    sell 物品 起始价格(单位：白银)

    别人出价过程中如认为合适，可以用命
令 accept 接受出价完成交易。

    如果中途想停止叫卖，用 sell stop 命
令来中止。\n
",
]));

	setup();
}
