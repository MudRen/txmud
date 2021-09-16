// Room: /d/path2/ch_t19.c

inherit ROOM;

void create()
{
	set("short", "高原土路");
	set("long", @LONG
你走在黄土高原上，抬眼看去，一望无际的黄土高原与天际
相连，天空则是格外的蓝，你看着远处起伏的山脉，不禁顿感心
情舒畅。南面就是黄河河套。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ch_t18",
  "west" : __DIR__"ch_t20",
]));
	set("no_clean_up", 0);
	set("outdoors", "path2");
	setup();
	replace_program(ROOM);
}
