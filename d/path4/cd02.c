// Room: /d/path4/cd02.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd01",
  "east" : __DIR__"cd03",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
