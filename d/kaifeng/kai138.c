// Room: /u/w/wangs/b/kai138.c

inherit ROOM;

void create()
{
	set("short", "东街路口");
	set("long", @LONG
开封城内主要街道，西边通往中心街。其他小街横巷，则依
主街交错布置，井然有序。它的北边就是开封城最有名的春来福
酒楼，南面通往开封城的衙门。所以这里的治安很好，大街上的
行人也并不用为安全担心。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai140",
  "north" : __DIR__"kai139",
  "west" : __DIR__"kai137",
  "east" : __DIR__"kai141",
]));

	set("outdoors","kaifeng");

	set("objects",([
	NPC_DIR"stdnpc/stdnpc_3" : 4,
]));

	setup();
	replace_program(ROOM);
}
