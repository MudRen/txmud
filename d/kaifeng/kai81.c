// Room: /u/w/wangs/b/kai81.c

inherit ROOM;

void create()
{
	set("short", "小茶馆");
	set("long", @LONG
座落在城市中最繁华地段的这个小茶馆每天都要接待很多客
人，据说每天光是从城外山上运来泡茶用的泉水就要三四十桶。
人们喜欢这里并不是因为这里的茶泡得特别好，而是因为这里有
个叫“张铁嘴”的说书先生。这个张铁嘴每天午后傍晚都要说上
一段江湖中发生的奇闻秩事。在大家眼里，江湖中发生的事情总
是很惊险，很神秘的，所以到这里喝下午茶的人就特别的多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai80",
]));
        set("objects",([
        __DIR__"npc/chaboss": 1,
]));

	setup();
	replace_program(ROOM);
}
