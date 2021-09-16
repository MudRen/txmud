// Room: chengxf12.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "卧室");
        set("long",@LONG
这里是长安丞相府的一间卧室，从卧室的格局来看，这里是
丞相府小姐的闺房，一种淡淡的幽香弥漫在空气中，绣床上绣着
大红的牡丹，东边一个梳妆台，西一个棋桌，上面有一局未下完
的残局，旁边的小桌有一张古琴，琴旁的小香炉正冒出凫凫的香
烟来，看来这位小姐琴棋之道，都很精通啊。从这面向南是后厅。
LONG
);
        set("exits", ([
  "south" : __DIR__"chengxf9",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "梳妆台": HIM"梳妆台上摆放着一些宫花，簪子之类的饰物，旁边有几盒胭脂和香粉。\n"NOR,
                "棋桌":   HIG"棋桌上一局棋没有下完，从局势上来看，白棋占尽优势，在棋西北\n"NOR+
                          HIG"角上一处打劫，竟然牵连全局。大有一子定乾坤之势。\n"NOR,
                "古琴":   HIY"这是一张古琴，从上面的花纹判断大概有几百年的历史了，显然是\n"NOR+
                          HIY"名手有上好的梧桐木制成的。\n"NOR,
]));

	set("objects",([
	__DIR__"npc/yahuan" : 2,
	__DIR__"npc/qianjin" : 1,
]));

        setup();
	replace_program(ROOM);
}