// Room: /wiz/louth/a/rou10.c

inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一间收拾的很干净的的石室，石室的墙壁上点着几根蜡
烛，地上铺着一些干草。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rou9",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/suibook" : 1,
]));
	setup();
	replace_program(ROOM);
}
