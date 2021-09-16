// Room: /wiz/louth/c/wwdao5.c

inherit ROOM;

void create()
{
	set("short", "武王道");
	set("long", @LONG
这是成都的武王道。由这里向西就是铁匠铺。由这里向东是
杜甫草堂。往北可以通过整个武王道。往南走是锦官路。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jguanlu4",
  "west" : __DIR__"tiejiangpu",
  "east" : __DIR__"caotang",
  "north" : __DIR__"wwdao4",
]));

	set("outdoors","chengdu");

	set("objects", ([
        NPC_DIR"stdnpc/stdnpc_3" : 2,
]));
	setup();
	replace_program(ROOM);
}
