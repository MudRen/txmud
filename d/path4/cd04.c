// Room: /d/path4/cd04.c

inherit ROOM;

void create()
{
	set("short", "��ؿ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cd03",
  "southeast" : __DIR__"cd05",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
