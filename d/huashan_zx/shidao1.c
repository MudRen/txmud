// Room: shidao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"殿前石阶"NOR);
	set("long",@LONG
这是一条从宫门通往紫霞宫正殿的青石铺就的甬道。石阶宽
约可四马并行，两边有青石护栏，护栏有古朴的石雕。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"guodaoe",
	"southwest":__DIR__"guodaow",
	"north":__DIR__"shidao2",
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}