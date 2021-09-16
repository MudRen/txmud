// Room: /d/changan/hockshop.c 当铺

inherit HOCKSHOP;

void create()
{
        set("short", "周记当铺");
        set("long", @LONG
这里是长安城一家很大的当铺，一进门，你便看见了高高的
柜台，柜台后一个一脸忠厚的店老板，正在忙着当着别人的东西。
他不停的叫着：收到破烂某某一件，值多少。旁边的帐房跟着在
记着帐，看来这里的生意还算是兴隆。门口有一个油黑发亮的牌
子(sign)，看得出来年代已经很古老了。由这里向东是南朱雀大
街。
LONG
        );
        set("item_desc", ([
                "sign": @TEXT
当铺交易的方法:
[ value | gujia ]     : 估价
[ pawn | dang ]       : 典当
sell                  : 卖
[ redeem | shu ]      : 赎回
list                  : 列表
[ buy | mai ]         : 买
TEXT
        ]) );
        set("exits", ([
                "south" : __DIR__"nroad6",
        ]));

	set("objects",([
		__DIR__"npc/zhou_xc"	: 1,
]));
        setup();
}