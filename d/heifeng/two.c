// Room: /d/heifeng/two.c

inherit ROOM;

void create()
{
	set("short", "��կ������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xiaolu1",
]));

	setup();
	replace_program(ROOM);
}