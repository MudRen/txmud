// Room: /wiz/louth/c/jguanlu3.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这是成都的锦官路。在这里向北是肉铺。向南走是一家棺材
铺。东西方向可以通过整个锦官路。
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guancaipu",
  "west" : __DIR__"jguanlu4",
  "east" : __DIR__"jguanlu2",
  "north" : __DIR__"roupu",
]));
        set("objects",([
        __DIR__"npc/sengren" : 1,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
