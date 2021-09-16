// Room: /d/huashan/zigongroom.c by pian 2000.8

inherit ROOM;

void create()
{
        set("short", "辞阳馆后院");
        set("long", @LONG
这是一间不大的房间，四白落地。西墙边有一张木床。床头
有一个锦盒。南边有一个案桌，供着三清老祖。一位老道人坐在
蒲团上打坐。
LONG
);

	set("exits",([
	"north" : __DIR__"ciyang",
]));

        set(SAFE_ENV,1);
        
        set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/shuiyue" : 1,
]));
        
        set("no_magic", 1);
        set("no_spells", 1);
        setup();
}
/*
void init()
{
        add_action("do_leave", "go");
        add_action("do_leave","east");
        add_action("no_quit", "climb");
}


int no_quit()
{
        object me;
        me = this_player();
        if (me->query_temp("zigong")) {
                tell_object(me, "你没交钱，还想溜吗? 没门儿! \n");
                message_vision("$N刚想溜，水月道长就挡住了大门! \n", me);
                return 1;
        }
        return 0;
}

int do_leave(string arg)
{
        object me;
        
        if (arg !="north") return 0;
        
        me = this_player();
        
        if (arg == "north") {
                if (me->query_temp("zigong")) 
                {
                        tell_object(me, "水月道长笑着对你说；请付净手钱。\n");
                        return 1;
                }
                else {
                        me->move(__DIR__"ciyang");
                        return 1;
                }
        }
        
        return 1;
}

*/
