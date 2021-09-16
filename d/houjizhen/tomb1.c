// tomb.c 
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","墓室");
	set("long", @LONG
这是一个很大的墓室，里面坐着不少人。墙上挂满了火炬，照得光
亮亮的。原来这就是丐帮的地下总舵，一群乞丐围着地图，似乎正在激
烈地讨论着什么。墙角处还有一口枯井(well)。
LONG
	);

        set("outdoors", "houjizhen");

	set("valid_startroom",1);
	set("item_desc",([
	"well" : "里面黑蒙蒙的，不知通向哪里。\n",
	]));
	set("objects",([
		__DIR__"npc/dizi1" : 1,
		__DIR__"npc/dizi2" : 1,
	]));
//        call_other("/clone/board/gb_board2", "???");
	setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
       	object me;
        me = this_player();

        if( arg=="well" )     {
        message("vision",
	me->name() + "深深地吸了一口气，一闭眼，往井里跳了下去。\n",environment(me), ({me}) );          		me->move(__DIR__"shangang");
        message("vision",me->name() + "从坟墓里冒了出来。\n",environment(me), ({me}) );
        return 1;       
}
}
