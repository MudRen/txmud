// Room: /d/path2/ch_k24.c

inherit ROOM;

void create()
{
	set("short", "土道");
	set("long", @LONG
这是一条黄土大道，虽然不很宽却是很平坦。你走在上面，
不时地擦抹着脸上的汗珠，不知不觉中感到有些累了。北面是一
片树林，穿过树林就是汶川镇了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/wenchuan/shulin2",
  "south" : __DIR__"ch_k25",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
