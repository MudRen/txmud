// Room: /d/path2/da_hou6.c

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你走在小路上，路的两则长着高大的杨树，像一排排的卫士
站立在路的两旁。西面是一片高粱地。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"da_hou7",
  "west" : __DIR__"da_hou5",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
