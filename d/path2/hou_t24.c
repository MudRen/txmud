// Room: /d/path2/hou_t24.c

inherit ROOM;

void create()
{
	set("short", "小土路");
	set("long", @LONG
这是一条草原小路，路的两侧是一片绿色的草原，草原上长
着各种各样的野花草。再向北去就到天水镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hou_t23",
  "north" : "/d/tianshui/skou",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
