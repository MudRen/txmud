// Room: /wiz/louth/c/fdjie2.c

inherit ROOM;

void create()
{
	set("short", "府道街");
	set("long", @LONG
这是成都的府道街。东面是茗茶坊，里面飘出的茶香弥漫在
空气中。南北方向则可以贯穿整个府道街。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie1",
  "east" : __DIR__"mingchafang",
  "north" : __DIR__"fdjie3",
]));

	set("objects",([
	NPC_DIR"xunpu" : 3,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
