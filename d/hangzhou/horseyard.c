// Room: /d/hangzhou/horseyard.c

inherit ROOM;

void create()
{
	set("short", "马场");
	set("long", @LONG
这里是杭州城的马场，专门为杭州城的军队提供马匹，同时
也为疲劳的旅人提供出租业务，使他们能够轻松的往来于各地。
马场中有一个粗木的围栏围着数十匹膘肥体壮的骏马。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guotaie3",
]));

	setup();
	replace_program(ROOM);
}
