// Room: /wiz/louth/c/liangfendian.c

inherit ROOM;

void create()
{
	set("short", "凉粉店");
	set("long", @LONG
这是一个很大的凉粉店，此店在成都已经有上百年的历史。
它做作的成都张老五凉粉、川北凉粉堪称成都一决，凉粉的味道
好，老少皆宜。听说有不少的大人物都曾来过这里品尝凉粉呢！
这里向南走就是万明路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wmlu3",
]));
        set("objects",([
        __DIR__"npc/huaboss" : 1,
]));

	setup();
	replace_program(ROOM);
}
