// xiaolu1.c
// by dicky

inherit ROOM;

void create()
{
set("short", "小路");
	set("long", @LONG
你正走在一片步满青苔的小路上，由于长时间没有人行走，路面显得
非常的滑，你情不自禁的放慢了脚步。小路一直想前延伸过去，看不到尽
头，四周一片寂静。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([ /* sizeof() == 1 */
        "northwest" : __DIR__"xiaolu2",
        "south" : __DIR__"zhulin3",
]));

	set("objects",([
		__DIR__"npc/dadao" : 1,
	]));

	setup();
	replace_program(ROOM);
}
