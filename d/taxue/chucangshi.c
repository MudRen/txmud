// chucangshi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "储藏室");
        set("long", @LONG
你一进门便闻到一股霉味，在门外射进来的阳光的照耀下，你看见这
里满屋的灰尘，成堆成堆的物品快堆满了整间房间。你很是奇怪为什么仆
役们离开时不把这些物品也带走。
LONG);

        set("exits", ([
              "west" : __DIR__"shilu3",
        ]));

        set("objects", ([
                __DIR__"obj/shengzi" : 1,
        ]));

        setup();
	replace_program(ROOM);
}
