// Room: /d/shaolin/lroad5.c

inherit ROOM;

void create()
{
	set("short", "过道");
	set("long", @LONG
这里是少林寺地处后院的过道，来这里的人很少，但是这里
的景致却很美，不远处有几排矮小的灌木，和幽静的小道相映成
趣，偶然传来一两声布谷鸟的叫声。几乎使你忘了，这里千年古
刹。从这里向西是地藏王殿，向东是演武场，南边是过道，西北
方是少林寺的后门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lroad4",
  "east" : __DIR__"yanwu",
  "west" : __DIR__"dizang",
]));
        set("objects",([
        __DIR__"npc/husi_seng" : 1,
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
