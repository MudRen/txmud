// Room: /u/w/wangs/b/kai64.c

inherit ROOM;

void create()
{
	set("short", "开封西街");
	set("long", @LONG
这条大街横贯东西，把开封城分成两半。北面的一半由于有
一条柳中河从城中穿过，所以以景至居多，间或有几间茶馆、饭
庄之类的建筑，是城中居民和游人们休闲游乐的好去处，南面则
分布了大大小小数百间店铺，无论衣食住行是应有尽有。此处向
北是天虹武场，南面是一家烤肉店。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"kai36",
  "west" : __DIR__"kai2",
  "east" : __DIR__"kai65",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
