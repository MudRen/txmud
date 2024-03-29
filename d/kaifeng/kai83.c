// Room: /u/w/wangs/b/kai83.c

inherit ROOM;

void create()
{
	set("short", "开封北街");
	set("long", @LONG
开封北街是一条横贯南北的大道，因为它还连接着九省通渠
大道，所以建造得格外宽阔。路上车水马龙，日夜不绝，北方运
送货物的车队从这里源源不断的分散至各家店铺，又带着开封的
货物从城中各处汇聚到这条马路上出城而去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"kai86",
  "south" : __DIR__"kai80",
  "west" : __DIR__"kai84",
  "east" : __DIR__"kai85",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
