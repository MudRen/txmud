// Room: /u/w/wangs/b/kai78.c

inherit ROOM;

void create()
{
	set("short", "兵器店");
	set("long", @LONG
这间兵器店听说也是南边那家武场的主人开的。年轻人最爱
舞刀弄枪，他便开武馆教人使刀使剑，又卖兵器供其所需，做生
意的眼光着实高明，而且据说这家主人还打算开一家医斋给人医
治刀伤，再开一家棺材铺专门给那些学会武功的好斗少年们收尸
送葬。这笔算盘打得如此之响，此人前途必不可限量。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kai72",
  "east" : __DIR__"kai77",
]));

        set("objects",([
        __DIR__"npc/tielaoban" : 1,
]));

	setup();
	replace_program(ROOM);
}
