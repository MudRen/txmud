// /d/hangzhou/changanw2.c

inherit ROOM;

void create()
{
        set("short", "长安西街");
        set("long", @LONG
你正走在城北的长安街上，这里向北不远就是杭州府的北城
门了，因此你可以看到不少的往来客商匆匆而过，街两旁没什么
特别繁华的地方，多是一些老字号。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"bank",
            "north"  : __DIR__"tearoom.c",
            "east"   : __DIR__"changanw1",
            "west"   : __DIR__"changanw3",
]));
        set("outdoors", "hangzhou");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

        setup();
        replace_program(ROOM);
}

