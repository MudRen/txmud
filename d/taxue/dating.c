// dating.c 大厅
// feng

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIG"大厅"NOR);
        set("long",@LONG
这里就是踏雪山庄大厅，气势威严，进来一眼就可以看到墙上有一幅
字画，正是李白的<<侠客行>>，气派非凡。但到了某些喜庆的日子，这里
就会张灯接彩，大摆宴席。
LONG);

	set(SAFE_ENV, 1);
	set("valid_startroom",1);

	set("exits",([
		"south" : __DIR__"huayuan",
		"west"  : __DIR__"zoulang3",
		"east"  : __DIR__"zoulang4",
		"northeast" : __DIR__"zoulang2",
                 	]));

        set("objects", ([
                __DIR__"npc/master4" : 1,
        ]));

	setup();
	load_board("board_taxue");
}
