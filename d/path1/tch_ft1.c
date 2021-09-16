// Room: /d/path1/tch_ft1.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，路的北面是一座座高山，南面则是片片
的树林。风儿吹过，你不禁感到阵阵凉意。西面不远到是“渡马
坡”了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cc_tch16",
  "east" : __DIR__"tch_ft2",
]));
	set("outdoors", "path1");
        set("objects", ([
        NPC_DIR"stdnpc/stdnpc_4" : 4,
]));

	setup();
	replace_program(ROOM);
}
