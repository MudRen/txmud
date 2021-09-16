// Room: /u/w/wangs/a/yu30.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是绯雨阁的一间寝室，只不知是哪位姐姐住在这里，
不过从收拾得干干净净，整整齐齐的屋子可以看出，一定是
位又漂亮，又贤惠的姐姐住在这里。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu29",
]));
        set("objects", ([
        __DIR__"npc/ning": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
