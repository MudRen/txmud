//shanlu3.c
//by dicky

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
你进入了一片小树林，走在林间小路上，密密麻麻的树林挡住了阳光，
这里显得十分阴暗，树木交错纵横，这里没有什么出路了，树上结满了不名
的果实，经过这里的路人常采来暂时充饥。
LONG
	);
        set("outdoors", "houjizhen");

	set("exits", ([
		"west" : __DIR__"shanlu2",
	]));

	set("objects",([
		__DIR__"npc/luren" : 1,
	]));


	setup();
//	replace_program(ROOM);
}

#include "heiyijob.h";

void init()
{
        add_action("do_cai", "cai");
}

int do_cai(string arg)
{
    object me;
    me = this_player();
    if (arg == "guo")
 	{   message_vision("$N伸手从树上摘下一个野果。\n", me);
     	new(__DIR__"obj/yeguo")->move(me);
     	return 1;
 	}
     return notify_fail("你要采什么? \n");
 }