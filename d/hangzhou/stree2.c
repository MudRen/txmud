// Room: /d/hangzhou/stree2.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这是杭州城外的一片树林，林中小鸟在不停地叽叫，仿佛在
向你暗示着什么。地上青草稀稀拉拉，一看就知道是人踏出的结
果。西面是杭州城外的黄土大道。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"spath2",
]));
	set("outdoors", "hangzhou");
        set("objects",([
        NPC_DIR"stdnpc/stdnpc_6" : 6,
]));


	setup();
	replace_program(ROOM);
}
