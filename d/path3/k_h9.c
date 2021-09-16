// Room: /d/path3/k_h9.c

inherit ROOM;

void create()
{
	set("short", "山林杂道");
	set("long", @LONG
这是一片山林，林中灌木丛生，一眼看不到边。丛林中时而
发出声响，像是有什么动物窜过。你不由得万分小心。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_h10",
  "north" : __DIR__"k_h8",
]));
	set("no_clean_up", 0);
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
