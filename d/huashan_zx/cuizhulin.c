// Room: huashan cuizhulin.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","翠竹林");
	set("long",@LONG
这里一片浓密的翠竹，粗壮的竹子每根都有胳膊粗细，竹子
中间吊着几个大沙袋，看样子这是华山弟子平时袋练功的地方。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"houdian",
]));
	set("outdoors", "huashan_zx");

	set("objects",([
	__DIR__"obj/shadai" : 3,
]));

	setup();
}
