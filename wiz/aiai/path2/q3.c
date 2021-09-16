// Room: /d/path2/q3.c

inherit ROOM;

void create()
{
        set("short", "石房子");
        set("long", @LONG
这是一间石头搭建的房子，由于长时间没人居住，地上已经
长出了杂草，屋子里几件简单的家具已经破败不堪，墙上不少地
方长着青苔。正面的墙上却有一块「石块」非常光滑。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"q2",
]));

        set("item_desc",([
        "石块" : "这块石头表面非常光滑，好像经常有人按。\n",
]));

        setup();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object ob,enter,xin,me = this_player();

        if(arg != "石块")
                return notify_fail("你要按什么？\n");

        if( (arg != "石块")
        || (me->query("class") != "huashan")
        || (me->query("quest/huashan_quest/name") != "飞贼展飞熊的踪迹")
        || !me->query("quest/huashan_quest/asked_zhang")
        || me->query("quest/huashan_quest/entered") )
                return notify_fail("你用力按了几下石块，可是什么反应也没有。\n");

        ob = find_object(__DIR__"dilao");
        if(!ob)
                ob = load_object(__DIR__"dilao");
        if(!ob)
                return notify_fail("华山“飞贼”任务出现错误，请向巫师报告。\n");

        if(!objectp(enter = ob->init_dilao(me)))
                return notify_fail("华山“飞贼”任务出现错误，请向巫师报告。\n");

        message_vision("$N脚下的石板“轰隆”一声突然翻起。\n",me);
        tell_room(this_object(),me->name()+"掉了下去，石板又翻了回来。\n",({me}));
        me->move(enter);
        me->set("quest/huashan_quest/entered",1);
                if ( objectp(xin=present("shouxin", me)) &&
                        xin->query("for_xiuxiu") )
                        destruct(xin);

        // 20分钟之内做连续做此任务次数过多，会随机提高任务难度
        if (me->query("zfx_start_time"))
        {
                if ( time() - (int)me->query("zfx_start_time", 1) < 1200 )
                {
                        me->add("zfx_in_20min", 1);
                }
                else 
                {
                        me->set("zfx_start_time", time());
                        me->set("zfx_in_20min", 1);
                }
        }
        else
        {
                me->set("zfx_start_time", time());
                me->set("zfx_in_20min", 1);
        }

        return 1;
}

