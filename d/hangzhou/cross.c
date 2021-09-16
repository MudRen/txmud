// /d/hangzhou/cross.c

inherit ROOM;

void create()
{
        set("short", "十字路口");
        set("long", @LONG
这里是民安街和长安街交汇的地方，也是最热闹的地方。不
时有官兵从这里经过，看来这里的治安很是不错。你四下看去，
心里琢磨着该先向哪个方向。
LONG
        );
        set("exits", ([ 
            "south"  : __DIR__"minan03",
            "north"  : __DIR__"minan02",
            "east"   : __DIR__"changane1",
            "west"   : __DIR__"changanw1",
]));

	set("objects",([
	__DIR__"npc/wushi" : 2,
]));

        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

