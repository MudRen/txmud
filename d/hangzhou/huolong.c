// Room: /d/hangzhou/huolong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sforest",
  "east" : __DIR__"smishi1",
  "north" : __DIR__"spath5",
]));

	setup();
	replace_program(ROOM);
}
