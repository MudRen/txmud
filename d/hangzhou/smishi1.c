// Room: /d/hangzhou/smishi1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"huolong",
  "east" : __DIR__"smishi2",
]));

	setup();
	replace_program(ROOM);
}
