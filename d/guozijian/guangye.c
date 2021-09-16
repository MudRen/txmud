// Room: /d/guozijian/guangye.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "广业堂");
	set("long", @LONG
这里是广业堂，是监生学习的地方，在这里主要是修行奇门
遁甲、八卦五行，是培养朝廷高级武将的地方。这几日可能是老
师病了，这里没有开课。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"xiudao",
]));
	set("objects", ([
		__DIR__"npc/wuguan"  : 1,
	]));
	setup();
	replace_program(ROOM);
}
