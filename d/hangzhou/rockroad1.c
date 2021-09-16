// Room: /d/hangzhou/rockroad1.c

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
你正走在一条碎石铺就的小路上，路两旁绿树成荫，繁花似
锦，真是让人着迷，往西不远，你就可以望见天下闻名的苏堤了
。
东路边有一个小小的院落。
LONG
	);
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"sudi3",
  "south" : __DIR__"rockroad2",
  "east" : __DIR__"wanghouse",
  "north" : __DIR__"cross1",
]));


        set("objects",([
        __DIR__"npc/beggar" : 1,
        NPC_DIR"xunpu" : 1,
]));

	setup();
	replace_program(ROOM);
}
