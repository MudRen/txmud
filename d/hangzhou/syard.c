// Room: /d/hangzhou/syard.c

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sforest",
]));
	set("outdoors", "hangzhou");

	setup();
	replace_program(ROOM);
}
