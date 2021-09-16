// Room: /wiz/louth/c/furuilou.c

inherit ROOM;
inherit SHOW_MSG;

void create()
{
	set("short", "瑞芙酒楼");
	set("long", @LONG
这里是成都最有名的酒楼－瑞芙酒楼。上至达官贵人，下至
小康之家，朋友聚会、喜庆宴席都会来这里操办。而瑞芙楼也正
如它的名字那样带给成都的百姓安康，快乐。
LONG
);

	set("night_long",@LONG
这里是成都最有名的酒楼－瑞芙酒楼。现在已经打烊了，白
天的喧闹已不复存在。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"fdjie3",
  "west" : __DIR__"chufang",
]));

	set_master("pao tang");

	set("no_fight", 1);
	set("valid_startroom", 1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));
	setup();
	load_board("board_chengdu");
}
