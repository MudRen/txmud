// Room: /wiz/louth/c/wwdao4.c

inherit ROOM;

void create()
{
	set("short", "武王道");
	set("long", @LONG
这是成都的武王道。由这里向西就是兵器铺。南北方向可以
贯通整个武王道。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"bingqipu",
  "south" : __DIR__"wwdao5",
  "north" : __DIR__"wwdao3",
]));
        set("objects",([
        __DIR__"npc/laoren" : 1,
        __DIR__"npc/dama" : 1,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
