// Room: /d/datong/zhai2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"zhai3",
  "south" : __DIR__"sizhai2",
]));

	setup();
	replace_program(ROOM);
}
