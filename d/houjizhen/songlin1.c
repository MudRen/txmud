// songlin1.
// by dicky

inherit ROOM;

void create()
{
        set("short","松林");
        set("long", @LONG
这里是一片茂盛的松林，林中静悄悄的，树林鸟语相间，遥相和呼，更为这寂
静的树林增添了几分神秘。东南方是一条小路，通向城镇的方向。
LONG
        );

	set("outdoors", "houjizhen");

        set("exits", ([
                "southeast" :__DIR__"lzxiaolu",
                "northeast" :__DIR__"songlin2",
        ]));
        
        setup();
        replace_program(ROOM);

}

#include "heiyijob.h";