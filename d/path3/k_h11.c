// Room: /d/path3/k_h11.c

inherit ROOM;

void create()
{
	set("short", "山林杂道");
	set("long", @LONG
这是一片山林，林中灌木丛生，一眼看不到边。丛林中时而
发出声响，像是有什么动物窜过。走这种地方，还是要小心些，
被蛇咬了可不是妙事。南面就是铜陵了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h12",
  "north" : __DIR__"k_h10",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
