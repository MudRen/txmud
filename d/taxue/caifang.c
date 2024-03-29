// caifang.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","柴房");
        set("long",@LONG
这里是踏雪山庄的柴房，这里看上去要比别人的柴房干净多了，这是
由于踏雪山庄的弟子经常在这里帮忙的缘故。角落里放着一堆柴，柴下好
象有什么东西。
LONG);

	set("exits",([
                "east" : __DIR__"shilu2",
	]));
	set("book_count",1);
	set("chai_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_pull","pull");
	add_action("do_pi","pi");
}

int do_move(string arg)
{
	object ob=this_player();
	object where=environment(ob);
	if (arg!="chai") return 0;
	if (!where->query("chai_moved"))
                return notify_fail("柴已经被移开了。\n");
	set("chai_moved",0);
        return notify_fail("柴被你移开了,出现了一块铁板。\n");
}

int do_pull(string arg)
{
	object ob,me=this_player();
	object where;
        where=environment(me);
	if (arg!="tieban") return 0;
	if( where->query("chai_moved") )
                return notify_fail("你周围没有这东西。\n");
        if((int)me->query_str()<22)
        	return notify_fail("你力气太小,没法拉起铁板。\n");
        message_vision("$N使出吃奶的力气，将铁板向上拉起。\n",me);
        if (!(where->query("book_count")))
              return notify_fail("下面什么都没有。\n");
        ob=new(__DIR__"obj/sword-book");
        ob->move(me);
        message_vision(HIG"$N发现了一本书！\n"NOR,me);
        where->set("book_count",0);
        return 1;
}

int do_pi(string arg)
{
	object me = this_player();

	if (arg != "chai" && arg != "mutou")
		return notify_fail("你要劈什么？\n");

	if (!present("sword", me))
		return notify_fail("你真是厉害，用手劈柴呀？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");

	if ((int)me->query_skill("sword", 1) > 31)
		return notify_fail("你用剑劈起木柴，但是已经无法提高你的基本剑术了。\n");

        if ( (int)me->query("kee")<20) 
	{
		me->receive_damage("kee", 10);
		write("你太累了，已经无法举起手中的长剑！\n");              
        return 1;
	}

        me->receive_damage("kee", random(20));
        message_vision("$N正用力地劈着柴。\n", me);  
        write("你努力地劈着柴，在劈柴的过程中你的基本剑术又进了一步。\n");
		me->improve_skill("sword", me->query("int"));       
	return 1;
}	
