// Room: /d/changan/zhubao_behind.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zhubao_room",
  "down" : __DIR__"didao/entry",
]));

	setup();
	replace_program(ROOM);
}
