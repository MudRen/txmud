// /d/hangzhou/bank.c

inherit BANK;

void create()
{
        set("short", "和计钱庄");
        set("long", @LONG
杭州处于交通要道，兼其物产丰富，风景优美，向来是富庶
之地，钱庄的生意当然是错不了的，和计银票通行南北，更是深
受信任，算得上财源广进，因此店铺虽然不大，却是防卫森严。
听说掌柜的本人更是身手了得。门口立着一块铜牌(pai)。
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changanw2",
]));


        set("item_desc", ([ /* sizeof() == 2 */
"pai" : "和计钱庄目前我们提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
",
]));

	set("no_beg", 1);
	set("objects",([
	__DIR__"npc/banker" : 1,
]));
        setup();
}
