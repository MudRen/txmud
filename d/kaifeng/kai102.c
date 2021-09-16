// Room: /u/w/wangs/b/kai102.c

inherit ROOM;

void create()
{
	set("short", "木材店");
	set("long", @LONG
这间小木材店就在开封南街右边的街角上。店面很窄，墙壁
上的石灰也已到剥落，甚至那块刻着“木材店”三字的牌匾，亦
是腐朽不堪，摇摇欲坠！，看上去毫不起眼，但它在开封城南一
带却极有名气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"kai100",
]));
        set("objects",([
        __DIR__"npc/mboss": 1,
]));

	setup();
	replace_program(ROOM);
}
