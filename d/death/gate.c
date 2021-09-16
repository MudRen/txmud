// gate.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "鬼门关");
        set("long", @LONG
这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座
高大的黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼
门关就无法再回阳间了。
LONG
);
        set("exits", ([
                "north" : "/d/death/gateway",
        ]) );

        set("no_magic", 1);

        setup();
	replace_program(ROOM);
}