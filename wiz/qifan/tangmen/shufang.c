// Room: /d/tangmen/shufang.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是一间简陋的书房，中间一张木桌摆着笔墨纸砚，一把小
竹椅放在旁边，右面放着一个小书架，上面零散的放着几本书。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"gd7",
]));

	set("objects", ([
	__DIR__"npc/master_yuan" : 1,
]));

	setup();
	replace_program(ROOM);
}
