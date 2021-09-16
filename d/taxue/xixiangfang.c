// xixiangfang.c 西厢房
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","西厢房");
        set("long",@LONG
这里是踏雪山庄的西厢房，房间里除了书还是书，只有墙上挂者着一
件兵器，那是踏雪山庄庄主的随身兵器，显示出在这里的是个文武双全的
人物。北面墙上有一个窗户，一扇窗子(window)大敞着。
LONG);

	set("exits",([
		"south" : __DIR__"xiting",
	]));
	
	set("item_desc",([
		"window" : "窗台上有一个小巧的脚印(sign)。\n",
		"sign" : "几只可爱的小脚印，看上去向一种美妙的步法，你不住想踏上去。\n",
	]));

        set("objects", ([
                __DIR__"npc/master3" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

int init()
{
	add_action("do_ta","ta");
//	add_action("do_jump","jump");
}

int do_ta(string arg)
	{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "sign" )
	return 0;
	if ((int)me->query_skill("dodge", 1) > 31)
	return notify_fail("你踏上可爱的小脚印，但是已经无法提高你的基本轻功了。\n");
        if ( (int)me->query("gin")<20) 
	{
		me->receive_damage("gin", 10 ,"tire");
		write("你太累了，已经抬不起脚了！\n");              
        return 1;
	}

        me->receive_damage("gin", random(20),"tire");
        message_vision("$N正在踏着窗台上的小脚印。\n", me);  
        write("你踏着小脚印，使你的基本轻功又进了一步。\n");
		me->improve_skill("dodge", me->query("int"));       
	return 1;
} 
