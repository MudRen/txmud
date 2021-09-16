// Room: /d/path1/py2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你延着崎岖的山路缓步而行。抬头看去，北面就是虎峪山，
山上绿色的丛林中好像有什么东西在晃动，你心中一动，不由得
加快脚步。南面是山间一条小路。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"py3",
  "east" : __DIR__"py1",
  "southdown" : __DIR__"lmj17",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
