// zhangfang.c
// by dicky

#include <ansi.h>
inherit BANK;

void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是山庄的帐房，四壁雪白的墙，中间有个大柜台，柜台前上方挂着一
块牌子（paizi）， 房里挤满了来存取钱款的山庄弟子，显得十分嘈杂。帐房
先生是个五十多岁的老头，看见你走了进来，他笑嘻嘻地迎了上来。
LONG
        );
        
	set("item_desc",([
		"paizi" :
          "这里是帐房，目前我们提供的服务有：

huan            兑换钱币
cunqian         存钱
quqian          取钱
chazhang        查帐
zhuan		转账。\n",
	]));
 
        set("no_beg", 1);

        set("exits", ([
               "south" : __DIR__"dongting",               
        ]));
        
        set("objects", ([
               __DIR__"npc/guanjia7" : 1,
        ]));

        setup();
}
