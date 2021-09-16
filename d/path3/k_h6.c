// Room: /d/path3/k_h6.c

inherit ROOM;

void create()
{
	set("short", "山林杂道");
	set("long", @LONG
这是一片山林，林中灌木丛生，一眼看不到边。丛林中时而
发出声响，像是有什么动物窜过，看起来是个埋伏的好地方。北
面是个岔路口。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h7",
  "northwest" : __DIR__"k_h5",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_5" : 4,
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
