// Room: /d/path1/py1.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你延着崎岖的山路缓步而行。抬头看去，北面是一座高山，
山上绿色的丛林中好像有什么东西在晃动，你心中一动，不由得
加快脚步。再向东去，就是柏云坡了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"py2",
  "east" : __DIR__"zjz4",
]));
	set("outdoors", "path1");
	setup();
	replace_program(ROOM);
}
