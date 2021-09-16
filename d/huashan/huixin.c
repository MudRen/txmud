// Room: /d/huashan/huixin.c

inherit ROOM;

void create()
{
	set("short", "回心石");
	set("long", @LONG
悬崖峭壁矗立眼前，上面刻有回心石三个大字，上面刻着一
个关于“郝老”的故事。仰望千尺幢，但见悬崖峭壁之上，陡窄
的石梯盘旋而上。面对此险境，便望而生畏，不敢攀登，回心转
意，循原路而下，这是回心石的又一种含义。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"e_daoguan",
  "east" : __DIR__"qianchi",
  "northwest" : __DIR__"xianguan",
]));
        set("outdoors", "huashan");
	setup();
	replace_program(ROOM);
}
