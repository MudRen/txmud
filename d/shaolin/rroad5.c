// Room: /d/shaolin/rroad5.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺的后院过道，北边有好大一片水池，名为放生
湖，里面不少很大的鱼。水池上飘满了浮萍，碧水悠悠，果然是
别样景致。这里往西是演武场，往南是过道，往东是白衣殿。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"rroad4",
  "east" : __DIR__"baiyi",
  "west" : __DIR__"yanwu",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
