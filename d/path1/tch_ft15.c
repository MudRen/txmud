// Room: /d/path1/tch_ft15.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，路的两侧都是高山，山上是郁郁葱葱的
树林，路的北面就是著名的长白山脉。偶尔有骑着快马的官兵与
你擦身而过，扬起阵阵尘土。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tch_ft14",
  "east" : __DIR__"tch_ft16",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
