// Room: /d/huanggong/yangxd.c

inherit ROOM;

void create()
{
	set("short", "养心殿");
	set("long", @LONG
这里是皇帝宁神静思和休息的地方。红毯铺地，一条案几上
放着一些批文。两个香炉正徐徐的冒着清烟....北墙上一副中堂
上书四个遒劲的大字《明静止水》你一走进这里就有一种精气清
新的感觉，一切烦燥都消失的无影无综，一种井中之月的感觉浮
上心头。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"longzm",
  "north" : __DIR__"donggdm",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}