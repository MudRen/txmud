// ehroad4  东环路

inherit ROOM;

void create()
{
        set("short", "东环路");
        set("long", @LONG
这里是长安城的东环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断。东环
路由这里向南延伸，往西走就是北环路了。
LONG
        );

	set("exits", ([
                "south"            : __DIR__"ehroad3",
                "west"             : __DIR__"nhroad1",
]) );

	set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_2" : 4,
]));

        setup();
	replace_program(ROOM);
}
