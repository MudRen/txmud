// Room: /d/path4/cd11.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"cd10",
  "south" : __DIR__"cd12",
  "northeast" : __DIR__"tree01",
]));
	set("outdoors", "path4");
	setup();
	replace_program(ROOM);
}
