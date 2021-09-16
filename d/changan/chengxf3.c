// Room: chengxf3.c

inherit ROOM;

void create()
{
        set("short", "花园");
	set("long", @LONG
这里是长安丞相府的花园，四周种着不少花花草草，一来到
这里，你闻到了阵阵的花香沁人肺腑，蜂蝶飞舞于其间，南边两
颗桐树间，吊着一个秋千，想必是丞相家小姐常来此游玩吧。从
这里向北是曲径。
LONG
	);

        set("exits", ([
  "north" : __DIR__"chengxf2",
]));
        set("outdoors","chengxf");

	set("objects",([
	__DIR__"npc/yahuan" : 1,
]));

	setup();
	replace_program(ROOM);
}