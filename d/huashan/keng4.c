// Room: /d/huashan/keng4.c

#include <ansi.h>

inherit ROOM;
inherit __DIR__"kuangkeng";

void create()
{
	set("short",HIC"矿坑"NOR);
	set("long",@LONG
这是一个巨大的矿坑，华山铸剑用的铁矿石都是从这里开采的。
LONG
);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"keng5",
  "west" : __DIR__"keng3",
]));

	setup();
}
