// Room: /d/hangzhou/jiyuan05.c

inherit ROOM;

void create()
{
	set("short", "茹梦房间");
	set("long", @LONG
这里是杭州名伎茹梦姑娘的房间，
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
