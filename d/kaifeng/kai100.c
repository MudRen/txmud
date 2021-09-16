// Room: /u/w/wangs/b/kai100.c

inherit ROOM;

void create()
{
	set("short", "南街路口");
	set("long", @LONG
从这里往北望就是中心街，再往远处就是开封府的标志建筑
“商周铜鼎”了，南面是一条宽广的大道，那是开封府的南街。
路西面是一家当铺，门口挂着一个招牌，上面写着“杨记”。东
边则是一家木材店。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai103",
  "north" : __DIR__"kai97",
  "west" : __DIR__"kai101",
  "east" : __DIR__"kai102",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
