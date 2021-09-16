// Room: /d/path2/ch_t28.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条黄土小路，路的两边稀疏地长着一些杂草，看起来
这里很少有人经过，显得十分荒凉。路沟边几只山羊正在吃草，
分不清是人养的还是野生的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t27",
  "southwest" : __DIR__"ch_t29",
]));
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_6" : 4,
]));

	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
