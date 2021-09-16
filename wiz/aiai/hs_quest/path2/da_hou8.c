// Room: /d/path2/da_hou8.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在小路上，路的一则长着高大的杨树，像一排排的卫士
站立在路的一旁。偶尔几个挑夫挑着担子经过，看来像是送货的
伙计。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"da_hou7",
  "south" : __DIR__"da_hou9",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
