// Room: /d/path5/kch41.c

inherit ROOM;

void create()
{
	set("short", "陡峭山路");
	set("long", @LONG
这是一条蜿蜒的小路，两旁灌木丛生，不时发出唏唏的声响。
你警惕地向四周看了看，并没有发现有什么危险。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch42",
  "northup" : __DIR__"kch40",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
