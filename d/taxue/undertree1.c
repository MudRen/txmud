// undertree.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "松阴之下");
  set ("long", @LONG
一棵高有数丈的大松树如伞如盖遮住了天空，松树上垂挂着许多荜萝葛藤
，中见隐见些小花。松树下有一大石台，上面刻了一个围棋盘，石台旁有三个
石凳。数丈外有一石碑，石碑上刻着「塟剑冢」三个大字。
LONG);

        set("outdoors", "taxue");

        set("exits", ([
               "south" : __DIR__"chitang",
	]));
         
        setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_touch", "touch");
}

int do_touch(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="shibei" && arg!="bei") )
		return notify_fail("你要触摸什么？\n");
	if(me->is_busy())
		return notify_fail("你很忙，不能做其他的事情！\n");
	if(me->query("class")!="taxue")	
		return notify_fail("你有何目的，跑到踏雪山庄干什么？\n");
	if(me->query("combat_exp") < 100000)	
		return notify_fail("你现在功力不够，还是回去脚踏实地的练习吧？\n");

	message_vision(HIG"突然一股清凉的风吹来，$N精神为之一振，体内充满了无穷活力！\n"NOR, me);
        me->set("gin", me->query("max_gin"));
        me->set("kee", me->query("max_kee"));
        me->set("sen", me->query("max_sen"));

	me->start_busy(3);

	return 1;
}
