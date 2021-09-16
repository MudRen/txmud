// /d/hangzhou/tearoom.c

inherit ROOM;

void create()
{
        set("short", "茶庄");
        set("long", @LONG
茶庄布置甚为雅致，翠竹做成的茶几上面摆设着一套精美的
茶具，茶童正在小心的为屋角的茶花浇水，整个屋中弥漫着西湖
龙井的清香。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"changanw2",
]));

	set("objects",([
	__DIR__"npc/tea_boss" : 1,
]));

        setup();
        replace_program(ROOM);
}

