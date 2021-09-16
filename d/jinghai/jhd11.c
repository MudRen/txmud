// Room: /d/jinghai/jhd11.c

inherit ROOM;

void create()
{
	set("short", "园中小路");
	set("long", @LONG
扑鼻的香气让你精神一爽，你游目四顾，落眼处尽是不知名
的簇簇鲜花。红花绿枝淹荫之间，几条小路深向花从深处。这里
是靖海公府前院的花园，主人为了让来访者宾至如归，对这个花
园煞是费了一番苦心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"jhd10",
  "west" : __DIR__"jhd17",
]));
        set("outdoors","jinghai");

	setup();
	replace_program(ROOM);
}
