// Room: /d/hangzhou/linbedroom.c

inherit ROOM;

void create()
{
	set("short", "员外卧房");
	set("long", @LONG
这里是林员外的卧房，林家虽然是豪门大户，可林员外的卧
房却很是简朴，南墙摆了一张大床，西面有一个檀木箱子，
上面还加了一把大锁。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"linpath5",
]));

	setup();
	replace_program(ROOM);
}
