// Room: /d/huashan/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"e_daoguan",
  "east" : __DIR__"qianchi",
  "northwest" : __DIR__"xianguan",
  "north" : __DIR__"huixin",
]));

	setup();
	replace_program(ROOM);
}
