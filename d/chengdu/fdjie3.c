// Room: /wiz/louth/c/fdjie3.c

inherit ROOM;

void create()
{
	set("short", "府道街");
	set("long", @LONG
这是成都的府道街。由这里向北能走到万明路。向南则一直
走到府道街的尽头。西面就是成都著名的是瑞芙酒楼。东面是成
都的东城门。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie2",
  "west" : __DIR__"furuilou",
  "east" : __DIR__"edoor",
  "north" : __DIR__"fdjie4",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_4" : 3,
]));

	setup();
	replace_program(ROOM);
}
