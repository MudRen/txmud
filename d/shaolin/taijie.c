// Room: /d/shaolin/taijie.c

inherit ROOM;

void create()
{
	set("short", "台阶");
	set("long", @LONG
这里是少林寺的通往前院广场和天王殿之间的台阶。抬头望
去，高耸的石阶似乎直上天际。从这里向北是宽阔的中院广场，
向南是天王殿。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tianwangdian.c",
  "south" : __DIR__"f_square",
]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
