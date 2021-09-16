// Room: /d/shaolin/dizang.c

inherit ROOM;

void create()
{
	set("short", "地藏王殿");
	set("long", @LONG
这里是少林寺的地藏王殿，又称大愿殿，正中供奉着地藏王
菩萨，香烟凫凫。在大殿的两边有一些壁画，画着地藏王经中的
故事。从这里向西是过道。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lroad5",
]));

	set("objects", ([
	__DIR__"npc/huineng" : 1,
]));

	setup();
	replace_program(ROOM);
}
