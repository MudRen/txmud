// Room: /d/hangzhou/smishi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"smishi4",
  "west" : __DIR__"smishi1",
  "east" : __DIR__"smishi3",
]));

	setup();
	replace_program(ROOM);
}
