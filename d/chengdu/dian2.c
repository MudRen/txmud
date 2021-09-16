// Room: /d/chengdu/dian2.c

inherit ROOM;

void create()
{
	set("short", "水果店后院");
	set("long", @LONG
这里就是水果店的后院，用竹席搭的凉棚遮盖了整个院子，
下面码满了各式各样的水果，一个年轻人正指挥伙计搬东西。
LONG
	);
	set("exits", ([
  "southwest" : __DIR__"shuiguodian",
]));

	set("objects", ([
	__DIR__"npc/xin" : 1,
]));

	setup();
	replace_program(ROOM);
}
