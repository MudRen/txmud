// Room: /d/path4/cd01.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/chengdu/out_chengdu_e",
  "east" : __DIR__"cd02",
]));

	setup();
	set("outdoors", "path4");
	replace_program(ROOM);
}
