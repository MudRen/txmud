// Room: /u/w/wangs/b/kai69.c

inherit ROOM;

void create()
{
	set("short", "李记珠宝行");
	set("long", @LONG
李记珠宝行不光是开封府最大的珠宝行，也是全国最有名的
珠宝行之一，店主人李玉堂是如今实力最大的商人之一，他在全
国各大城市都有生意，他名下的产业不光有珠宝行，还有钱庄、
药店、赌场、妓院等等，只要是赚钱的生意都有他的一份，因此，
在李记店铺里买东西可以绝对的放心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kai68",
]));
        set("objects",([
        __DIR__"npc/liboss": 1,
]));

	setup();
	replace_program(ROOM);
}
