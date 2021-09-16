// Room: /wiz/louth/c/bingqipu.c

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这是一间很大的房子，屋子里摆放着各式各样的兵器，几个
人还在仔细的挑选，一个伙计再给他介绍着什么。看样子这里是
一家卖兵器的铺子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wwdao4",
]));
        set("objects",([
                __DIR__"npc/songboss" :1,        
        ]));

	setup();
	replace_program(ROOM);
}
