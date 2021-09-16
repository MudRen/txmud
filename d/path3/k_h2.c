// Room: /d/path3/k_h2.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条黄土铺成的官道，路上喷洒了不少的清水，以免激
起太多的尘土。由此再向西不远，就是开封府了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"k_h1",
  "east" : __DIR__"k_h3",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
