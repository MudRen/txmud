// Room: /d/jinghai/jhd16.c

inherit ROOM;

void create()
{
	set("short", "山庄大厅");
	set("long", @LONG
这是一处不小的厅堂，大概能容纳一、二百人，每月一次的
掌门人与大小头目会商帮务就在这里进行。中间一张虎皮大椅的
前面是两排整齐的红木小凳，中间一条红地毯一直铺到虎皮椅前，
两帮是几盏碗口粗的油灯，来到这里使人不禁使人肃然起敬。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jhd17",
  "west" : __DIR__"jhd20",
  "south" : __DIR__"jhd15",
]));

	setup();
	replace_program(ROOM);
}
