// Room: /wiz/louth/c/jguanlu2.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这是成都的锦官路。在这里向北是朗中苏理明的家。东西方
向可以通过整个锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jguanlu3",
  "east" : __DIR__"jguanlu1",
  "north" : __DIR__"langzhong",
]));

	set("objects",([
	NPC_DIR"xunpu" : 3,
        NPC_DIR"stdnpc/stdnpc_3" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
