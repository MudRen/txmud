// Room: /d/fengtian/shu.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jjf5",
]));

	setup();
	replace_program(ROOM);
}
