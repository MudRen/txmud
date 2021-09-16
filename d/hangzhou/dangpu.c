// Room: /d/hangzhou/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "常记当铺");
	set("long", @LONG
这是一间大当铺，看得出这里生意不错，大部分顾客都是从
街对面的赌场里出来的赌客，和一些倒霉的商客，还有一些来历
不明的人到这里低价出售一些珍贵的物品。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"minan05",
]));

	set("objects",([
	__DIR__"npc/hockboss" : 1,
]));

	setup();
}
