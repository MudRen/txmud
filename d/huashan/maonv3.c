// Room: /d/huashan/maonv1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"毛女洞底"NOR);
	set("long", @LONG
四周火热的空气让你透不过气来，地上有涔涔的水流也冒着
白色的蒸气。你向四周打量，突然，你看到一又血红的眼睛闪着
莹莹的红光。竟是一只小牛犊大小的血蟾，它正一动不动地盯着
你。
LONG
	);
	set("no_clean_up", 0);
	
	set("exits", ([ /* sizeof() == 1 */
  	//"out" : __DIR__"maonv2",
  	//"southdown":__DIR__"maov3.c",
]));
	set("objects", ([__DIR__"npc/xuechan":1 ]));
	setup();
	set("indoors", "huashan");
	replace_program(ROOM);
}
