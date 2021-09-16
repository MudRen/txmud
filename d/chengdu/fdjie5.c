// Room: /wiz/louth/c/fdjie5.c

inherit ROOM;

void create()
{
	set("short", "府道街");
	set("long", @LONG
这是成都的府道街。由这里向北就是万明路。由这里向西是
赌场。向东是裁缝铺。向南则一直走到府道街的尽头。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie4",
  "west" : __DIR__"duchang",
  "east" : __DIR__"caifengpu",
  "north" : __DIR__"wmlu1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
