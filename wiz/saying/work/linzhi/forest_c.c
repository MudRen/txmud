//forest_c.c 原始森林中心。
inherit ROOM;
int do_climb(string arg);
int have=0;
void create()
{
        set("short","原始森林");
        set("long", @LONG
走在原始森林中，只见各种树木遮天蔽日。刚经过单调高原
景色的你开始还欣赏满目的绿色，渐渐的也厌烦起来，耳朵里也
充满了安静的声音，你甚至怀疑是不是只有自己一个人在，看着
千篇一律的树木，你忽然觉得其中一株大树很不寻常。
LONG
        );
        set("exits", ([
        "east":__DIR__"forest5",
        "west":__DIR__"forest4",
        "south":__DIR__"forest6",
        "north":__DIR__"forest5",
]));
        set("item_desc",([
        "大树":"你仔细观察，忽然听到密密的枝叶中似乎有野兽的咻咻声。\n",
]));
        setup();
}
void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{
        object me;
        object ob;
        me=this_player();
        if (!arg||arg!="大树")
        {
                tell_object("你要往哪里爬？\n",me);return 0;
        }
        if (arg=="大树")
        {
                if (!(int)me->query_temp("mark/圣树"))
                {
                        message("vision","忽然周围的树木一阵晃动，跳出了几个全身武装的猎户。\n",environment(me));
                        for(int i=0;i<2;i++)
                                {
                                        ob=new(__DIR__"npc/tree_guardian");
                                        ob->move(__FILE__);
                                        message("vision","猎户低吼道：想招惹圣兽嘛？找死！\n\n",environment(me));
                                        ob->set_leader(me);
                                        ob->kill_ob(me);
                                        me->fight_ob(ob);
                                        return 1;
                                }
                }
                else
                {
                        message_vision("$N抱住大树，灵活的爬了上去。\n",me);
                        me->move(__DIR__"tree1");
                        message_vision("$N从下面爬了上来。\n",me);
                        return 1;
                }
        }
}
