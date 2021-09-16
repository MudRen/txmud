// Room: /d/shaolin/lwc_w.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这是一处宽阔的空场，这里是少林寺僧人练功的地方，场上
摆着石锁、沙袋等一些练功的器械，只要不是功课的时间这里总
能看到三三两两的僧人在练功、切磋。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad2",
]));

	set("objects", ([
	__DIR__"npc/kongzheng" : 1,
	__DIR__"obj/shisuo" : 2,
]));

	setup();
	replace_program(ROOM);
}
