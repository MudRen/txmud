// Room: /u/w/wangs/a/yu86.c

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是绯雨阁姐姐的私人房间，床上被褥叠得整整齐齐，
地面也是一尘不染。你这么冒冒失失的闯了进来似乎有些不
太礼貌。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yu84",
]));
        set("objects", ([
        __DIR__"npc/huan": 1,
                        ]) );

	setup();
	replace_program(ROOM);
}
