// Room: /d/path2/ch_k23.c

inherit ROOM;

void create()
{
	set("short", "土道");
	set("long", @LONG
这是一条黄土大道，虽然宽阔却不是很平坦。你走在上面，
不时地擦抹着脸上的汗珠，不知不觉中感到有些累了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ch_k22",
        "south" : "/d/wenchuan/tulu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
