// /d/changan/eroad6  连德街

inherit ROOM;

void create()
{
        set("short", "连德街");
        set("long", @LONG
这是长安城的东大街，由于靠近长安城的东北角，想必是生
意也不不大好做，所以在这里做生意的人很少，来往的人也就更
少了，只有在不远处有一家铁匠铺“叮叮当当”打着铁，才使这
里有一点点活力。南边和北边是长安的东大街，西边有一个打铁
铺子。
LONG
        );
       set("exits", ([
                "north"           : __DIR__"eroad7",
                "west"            : __DIR__"ironroom",
                "south"           : __DIR__"eroad5",
]) );
        set("outdoors","changan");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 3,
]));

        setup();
	replace_program(ROOM);
}
