// Room: /d/changan/shanghang.c

inherit SHOP;

void create()
{
	set("short", "龙辉商行");
	set("long", @LONG
这是一间不大的店面，里面乱七八糟的摆着各式各样的东西，
小到一盘一碗，大到珠宝古董什么都有，一看就是一个收购各种
物品的二道贩子商行。后面大概是一个仓库，门口挂着一块牌子
(paizi)不知写了些什么。
LONG
	);

	set("item_desc", ([
	"paizi" : "收购各式物品，免费代客估价。\n",
]));

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"eroad3",
]));

	set("objects",([
	__DIR__"npc/shop_waiter" : 1,
]));

	setup();
}