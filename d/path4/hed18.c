// Room: /d/path4/hed18.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"hed19",
  "northeast" : __DIR__"hed17",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
