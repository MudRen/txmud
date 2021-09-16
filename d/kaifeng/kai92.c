// Room: /u/w/wangs/b/kai92.c

inherit ROOM;

void create()
{
	set("short", "开封北街");
	set("long", @LONG
开封北街是一条横贯南北的大道，因为它还连接着九省通渠
大道，所以建造得格外宽阔。路上车水马龙，日夜不绝，北方运
送货物的车队从这里源源不断的分散至各家店铺，又带着开封的
货物从城中各处汇聚到这条马路上出城而去。路西边是长青路，
东边是兵营，再往北就是开封北门了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ndoor",
  "south" : __DIR__"kai89",
  "west" : __DIR__"kai32",
  "east" : __DIR__"kai93",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
