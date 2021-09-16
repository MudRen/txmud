// Room: /wiz/louth/c/jguanlu6.c

inherit ROOM;

void create()
{
	set("short", "锦官路");
	set("long", @LONG
这里是成都的锦官路。南边是一家普通的民居。东西方向则
贯穿成都北部的锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"minjv",
  "west" : __DIR__"jguanlu5",
  "east" : __DIR__"jguanlu7",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_1" : 4,
]));

	setup();
	replace_program(ROOM);
}
