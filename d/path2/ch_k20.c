// Room: /d/path2/ch_k20.c

inherit ROOM;

void create()
{
	set("short", "黄土大道");
	set("long", @LONG
这是一条黄土大道，虽然宽阔却不是很平坦。你走在上面，
不时地擦抹着脸上的汗珠，不知不觉中感到有些累了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"ch_k19",
  "southwest" : __DIR__"ch_k21",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
