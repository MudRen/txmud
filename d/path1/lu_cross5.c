// Room: /d/path1/lu_cross5.c

inherit ROOM;

void create()
{
	set("short", "松林小道");
	set("long", @LONG
这是一片松树林，高低不等的松树参差不齐，时而一枚松果
掉在你的身边，发出“噗噗”的声响。若不仔细观察，很难发现
路在何方。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tch_ft4",
  "southeast" : __DIR__"lu_cross4",
]));
	set("outdoors", "path1");

	set("objects",([
	__DIR__"npc/tufei" : 2,
]));

	setup();
	replace_program(ROOM);
}
