//dangpu.c 林芝村的当铺
inherit HOCKSHOP;
void create()
{
        set("short", "【百年老当】");
        set("long", @LONG
这里是林芝村唯一的一家当铺，虽然这里的商业不是特别繁
荣，但是由于林芝是西藏地区人口比较密集的地区，当铺的生意
还是相当不错。一进门迎面是一个牌子（paizi），当铺老板坐
在高高的柜台后面看着你。
LONG
        );
        set("item_desc", ([
                "paizi": @TEXT
[value | gujia ]     : 估价
[pawn  | dang  ]     : 典当（此项业务暂停）
[sell          ]     : 卖
[redeem| shu   ]     : 赎回
[list          ]     : 列表
[ buy  | mai   ]     : 买
TEXT
]));
        set("exits", ([
        "north":__DIR__"lz_eroad2",
        ]));
        set("objects",([
                __DIR__"npc/d_boss":1,
]));
        setup();
}
