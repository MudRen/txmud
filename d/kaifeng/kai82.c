inherit BANK;

void create()
{
	set("short", "开封钱庄");
	set("long", @LONG
这是开封城里最大的一家钱庄，它大概已经有几百年的历史
了。信用非常好，在全国各地都有分店。钱庄发出的银票，走遍
天下都可通用；行商客旅，若觉得路上携带银两不便，就可以到
这种钱庄去换“银票”。柜台上方挂着一个牌子(paizi)。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai80",
]));

        set("item_desc", ([
	"paizi" :  "开封钱庄目前提供的服务有：
huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账
",
]));

        set("objects",([
        __DIR__"npc/jin": 1,
]));

	setup();
}
