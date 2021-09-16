// Room: /d/kaifeng/kai111.c

inherit ROOM;

void create()
{
	set("short", "李记药铺");
	set("long", @LONG
李记药铺不光在开封很有名，有很多外地的病人们都赶到这
里抓药，这是因为药铺的主人也是一位名医，他的名子已经没有
几个人知道了，大家都管他叫“李要命”，不过这不是说他喜欢
杀人，而是说只要你还没断气，他就能从阎王手里把你的命要回
来，由此可见他的医术之高明。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chenlaoban" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"kai106",
  "north" : __DIR__"yaofang2",
]));

	setup();
	replace_program(ROOM);
}
