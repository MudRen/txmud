// Room: /d/shaolin/xiaolu1.c

inherit ROOM;

void create()
{
	set("short", "蜿蜒小路");
	set("long", @LONG
这是一条大青石铺就的蜿蜒的上山小路，路旁是高大蔽日的
松树林，偶尔回荡着几声鸟鸣。路上总能遇上三三两两的进香客
满脸虔诚，由这里一直向北就是少林寺了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"jjting",
  "southwest" : __DIR__"xiaolu2",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
