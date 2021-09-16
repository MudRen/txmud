// fenmu.c
// by dicky

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short","坟场");
        set("long", @LONG
这里是踏雪氏的坟场， 踏雪氏死后都要被安葬这里,世世代代, 无一例
外。每到清明时分, 踏雪后裔都要在这里祭祖。
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
		return notify_fail("你正忙着呢。\n");

        if ( me->query_temp("ketou_times") == 0 )
        {
                message_vision("$N磕头磕得晕了过去。\n", me);
                me->set_temp("ketou_times",
			1+random(me->query_skill("force", 1)));
                me->unconcious();
                return 1;
        }

        me->add_temp("ketou_times", -1);        

        message_vision("$N虔诚地跪下来，在墓碑面前磕头。\n", me);

	if ( random (30) == 10 
        && !present("force book", me)
        && query("book_count") >= 1)
        {
        add("book_count", -1);
	ob=new(__DIR__"obj/force-book");
	ob->move(this_object());
                tell_object(me, "突然你面前，啪地一声掉下一本内功心法！\n");
        }
        return 1;
}
