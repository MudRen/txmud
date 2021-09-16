// Room: /d/changan/npc/fruitroom.c

inherit ROOM;

void create()
{
	set("short", "水果铺");
	set("long", @LONG
走进这里你的眼都花了，一排排的货架上整齐的码放着五颜
六色的各种水果，有翠绿圆润的大西瓜、焦黄饱满的大鸭梨、红
润欲滴的苹果、香蕉、菠萝、黄杏、李子……还有许多叫不出名
子的水果，哇，你的口水已经滴到衣服上了。
LONG
	);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wroad5",
]));

	if(random(20) < 4)
	set("hide_exits",([
	"northwest" : __DIR__"hideroom",
	]));

	set("objects",([
	__DIR__"npc/fruit_seller" : 1,
]));
	setup();
	replace_program(ROOM);
}
