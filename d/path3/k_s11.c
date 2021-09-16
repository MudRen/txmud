// Room: /d/path3/k_s11.c

inherit ROOM;

void create()
{
	set("short", "竹林小路");
	set("long", @LONG
你走在一条竹林小路上，路的两旁长满了参差不齐的竹子。
时而传来咕咕的声叫，不知是什么鸟的暗语。你四周看了一下，
没有发现什么意外的情况。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s12",
  "north" : __DIR__"k_s10",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 4,
]));

        set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
