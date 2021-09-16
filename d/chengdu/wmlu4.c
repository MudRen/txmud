// Room: /wiz/louth/c/wmlu4.c

inherit ROOM;

void create()
{
	set("short", "万明路");
	set("long", @LONG
这里是成都的万明路。由这里向南就是威武镖局。东西方向
则可以贯穿整个万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"biaojv",
  "west" : __DIR__"shizi1",
  "east" : __DIR__"wmlu3",
]));

	set("outdoors","chengdu");

        set("objects",([
        NPC_DIR"stdnpc/stdnpc_2" : 4,
]));

	setup();
	replace_program(ROOM);
}
