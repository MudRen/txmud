// fenmu.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","�س�");
        set("long", @LONG
������̤ѩ�ϵķس��� ̤ѩ������Ҫ����������,��������, ��һ��
�⡣ÿ������ʱ��, ̤ѩ���ᶼҪ��������档
LONG);
        set("exits", ([
                "east" : __DIR__"shilu4",
        ]));

        set("book_count",2);
        
        setup();
}

void init()
{
	if (!this_player()->query_temp("ketou_times"))
	        this_player()->set_temp("ketou_times",
			1+random(this_player()->query_skill("force", 1)));
        add_action("do_ketou", "ketou");
}

int do_ketou()
{
        object me, ob;

        me = this_player();
                
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N��ͷ�ĵ����˹�ȥ��\n", me);
                me->set_temp("ketou_times",
			1+random(me->query_skill("force", 1)));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);        

        message_vision("$N�ϵع���������Ĺ����ǰ��ͷ��\n", me);

	if ( random (30) == 10 
        && !present("force book", me)
        && query("book_count") >= 1)
        {
        add("book_count", -1);
	ob=new(__DIR__"obj/force-book");
	ob->move(this_object());
                tell_object(me, "ͻȻ����ǰ��ž��һ������һ���ڹ��ķ���\n");
        }
        return 1;
}
