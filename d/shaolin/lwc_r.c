// Room: /d/shaolin/lwc_r.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一处宽阔的空场，这里是少林寺僧人练功的地方，场上
摆着石锁、沙袋、木人等一些练功的器械，只要不是功课的时间
这里总能看到三三两两的僧人在练功、切磋。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"rroad2",
]));

	set("objects", ([
	__DIR__"npc/muren" : 2,
]));

	setup();
	replace_program(ROOM);
}
