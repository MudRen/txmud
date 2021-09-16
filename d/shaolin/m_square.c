// Room: /d/shaolin/m_square.c

inherit ROOM;

void create()
{
	set("short", "中院广场");
	set("long", @LONG
这里是少林寺的中院广场，广场中央是一个巨大的石质香炉，
这里可以说是少林寺最开阔的地方了，四下的禅房僧舍，尽入眼
底，耳边隐隐传来晚课的钟声，俨然如禅诗中所记：
        缁衣夜梦入空门，释祖青灯覆钵盆。
        旧衲寒山增暮影，芒鞋古道印苔痕。
        轮回十万无为障，世界三千有业魂。
        但愿身归清静处，斜阳晚颂伴黄昏。
从这里东西两边分别东广场和西广场，北是雄伟的大雄宝殿，南
面是肃穆的天王殿。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"baodian",
  "south" : __DIR__"tianwangdian",
  "east" : __DIR__"e_square",
  "west" : __DIR__"w_square",
]));
        set("objects", ([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
