// Room: /d/path4/hed01.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hed02",
  "north" : "/d/hangzhou/out_hangzhou_s",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
