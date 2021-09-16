inherit ITEM;

void create()
{
        set_name("箱子", ({ "creat"}) );
        set_weight(1200);
        set_max_encumbrance(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "口");
		set("long", "这是一口上边落满灰尘的木箱子。\n");
	}
}

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object me,ob,obj;
        me = this_player();

        if (arg != "箱子" && arg != "creat")
                return notify_fail("你要打开什么？\n");

        if (me->query_temp("mark/open_creat") < 6 )
        {
                message_vision("$N小心翼翼的打开了木头箱子,发现里边还是一个箱子.\n",me);
                ob=new(__DIR__"creat");    
                ob->move(me);
                me->add_temp("mark/open_creat",1);
                return 1;
        }

	if(sizeof(filter_array(children(__DIR__"yxiao"),(: clonep :))) > 0 )
		return notify_fail("你打开了最后一口箱子,是空的.\n");

	message_vision("$N抱着最后一线希望,打开了箱子,终于发现了要找的白玉箫.\n",me);
	obj=new(__DIR__"yxiao.c");
	obj->move(me);
	return 1;
}

