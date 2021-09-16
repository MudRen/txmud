// Room: /u/w/wangs/b/kai33.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这户人家静消消的，好像没有一个人，你站在屋子里左右看
了看，灶里的火还没熄，饭桌上摆着几份没刷的碗筷说明这里的
人才出去不久，院子里的拐角处摆放着几只断裂的独脚车轮，但
你却没有看到车子，看来这家人是有事情推四出去了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai32",
]));

	setup();
	replace_program(ROOM);
}
