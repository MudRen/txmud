// Room: /d/shaolin/taijie1.c

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是一条由整条大青石铺就的宽大石阶，这里香客、僧人来
往不断，两旁的护寺僧人手持木棍面色庄严，几位迎来送往的知
客僧笑容满面。石阶的尽头就是少林寺高大的山门。
LONG
	);

	set("night_long", @LONG
这是一条由整条大青石铺就的宽大石阶，向下望去是一条山
间小路，向上看石阶的尽头就是少林寺高大的山门。
LONG
	);

        set("NONPC",1);
	set("outdoors", "shaolin");

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"door",
  "southdown" : __DIR__"taijie2",
]));

	setup();
	replace_program(ROOM);
}
