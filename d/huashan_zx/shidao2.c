// Room: shidao1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"殿前石阶"NOR);
	set("long",@LONG
这是一条从宫门通往紫霞宫正殿的青石铺就的甬道。石阶宽
约可四马并行，两边有青石护栏，护栏有古朴的石雕。东边是一
片草地，再远一点可以看到一个小小的石亭。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"south":__DIR__"shidao1",
	"north":__DIR__"shidao3",
	"east":__DIR__"caodi1",
]));



	set("outdoors", "huashan_p");
	setup();
	replace_program(ROOM);
}