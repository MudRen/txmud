// Room: /u/w/wangs/b/kai9.c

inherit ROOM;

void create()
{
	set("short", "虹日路");
	set("long", @LONG
这条路通向开封城内的一些休闲景点，因而路两旁全都种满
了柔美的垂柳。路上偶然能看到几名外地来的游客正对着路边的
景致指指点点。你呼吸着清新的空气，耳边再无噪杂的尘世喧嚣，
心情顿时为之一畅。这里向东是一座小小的石拱桥横架在柳中河
上，你不禁欲立身其上，饱览沿河风光了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai16",
  "south" : __DIR__"kai4",
  "east" : __DIR__"kai11",
]));

	set("outdoors","kaifeng");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
