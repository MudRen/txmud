// Room: kuang.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIC"矿场"NOR);
	set("long",@LONG
这里一片繁忙的景向，向下可以看见一块数丈直径的黑色巨
石。几十个华山派的弟子用凿子和铁锤在一点一点地分解这块巨
石。想来这石头一定很是坚硬，因为你身边的矿车里只装了一个
江浅浅的底。
LONG

);
	set("exits", ([ /* sizeof() == 3 */
	
	"down":__DIR__"yunshi",
	"northup":__DIR__"luoyun",
]));

	setup();
	replace_program(ROOM);
}
