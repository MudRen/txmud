// Room: /d/huashan/xiaolu1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "半山腰");
        set("long", @LONG
华山在五岳中以险闻名，果然名不虚传。连绵的山岭直拔而
起，山披苍松翠柏；时有氤氲的雾气弥漫山腰；山路时隐时现。
你身旁立着一块半人高的石碑 (bei)，上面字迹古朴而遒劲。一
条山道连绵向北消失在山岭间，山道两边零星散布着作小买卖的
摊档。
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"xiaolu2",
  "southdown" : "/d/huayin/tl9",
]));

                set("item_desc", ([ /* sizeof() == 1 */
                "bei" : HIR"
                华 山 天 险\n\n"NOR,
        ]));

	set("objects",([
	__DIR__"npc/fengnong" : 1,
	__DIR__"npc/tiaofu" : 1,
]));
        set("outdoors", "huashan");
        setup();
        replace_program(ROOM);
}
