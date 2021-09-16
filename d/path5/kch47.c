// Room: /d/path5/kch47.c

inherit ROOM;

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
你走过这里，只见两旁都是成遍的稻田。一些农民正在田地
里忙碌着。田隙边有几间简陋的茅草屋，像是农民休息的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"kch46",
  "east" : __DIR__"kch48",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
