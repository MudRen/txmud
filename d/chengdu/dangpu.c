// Room: /wiz/louth/c/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一出很大的厅堂，门口的门帘上印着一个大大的“当”
字。柜台足有一人高，上面还钉着铁栅栏。柜台里不断传出算盘
声和伙计的吆喝声。柜台边上立着一块木牌(sign)。
LONG
);

	set("item_desc", ([
		"sign": @TEXT
本店办理以下业务:
[ value | gujia ]     : 估价
[ pawn | dang ]       : 典当
sell                  : 卖
[ redeem | shu ]      : 赎回
list                  : 列表
[ buy | mai ]         : 买
TEXT
        ]) );


	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fdjie4",
]));

        set("objects",([
        __DIR__"npc/jiang" : 1,
]));
	setup();
}
