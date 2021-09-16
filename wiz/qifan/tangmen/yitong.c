// Room: /d/tangmen/yitong.c

inherit ROOM;

void create()
{
	set("short", "一统堂");
	set("long", @LONG
这里就是唐家堡的一统堂，每年的正月各地的唐门弟子都会
赶回唐家堡，正月十八堡主会在这里召集各头目议事。高大的殿
堂在蜀中绝无仅有，四处雕梁画栋。正中是一把巨大的红木太师
椅，后面一扇巨大的屏风上雕刻着蟠龙飞凤。
LONG
	);
	set("exits", ([
  "south" : __DIR__"myuan",
  "north" : __DIR__"xiangfang",
]));

	set("objects", ([
	__DIR__"npc/master_zhen" : 1,
]));

	setup();
	replace_program(ROOM);
}
