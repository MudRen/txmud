// Room: /wiz/louth/a/yu92.c

inherit ROOM;

void create()
{
	set("short", "绯雨阁后院");
	set("long", @LONG
这里是绯雨阁后院。走到这里，花香味更加浓烈了。你
仔细一看，遍地种满了奇异的花草，一群群蜜蜂、蝴蝶在花
丛中飞舞。东西有两间休息室，所以很少有人在这里喧闹。
南边是绯雨阁的后门。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuantianer" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu93",
  "north" : __DIR__"yu37",
]));

	set("outdoors","feiyu");
	setup();
	replace_program(ROOM);
}
