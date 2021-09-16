// Room: /u/w/wangs/b/kai151.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
此时正是煮晚饭的时候，厨房里热气蒸腾，只听见锅铲声
碗碟声，吆喝声，众声错杂在一起，乱的一塌糊涂。好大的一
个厨房，工作的厨役约有数十名，由于厨房里太热的关系，厨
役们一个个赤着上身，下身反围白布一条。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai149",
]));

	setup();
	replace_program(ROOM);
}
