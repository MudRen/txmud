// Room: /d/path4/hed17.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed18",
  "north" : __DIR__"hed16",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
