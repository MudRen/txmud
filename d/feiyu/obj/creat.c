inherit ITEM;

void create()
{
        set_name("����", ({ "creat"}) );
        set_weight(1200);
        set_max_encumbrance(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "����һ���ϱ������ҳ���ľ���ӡ�\n");
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

        if (arg != "����" && arg != "creat")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->query_temp("mark/open_creat") < 6 )
        {
                message_vision("$NС������Ĵ���ľͷ����,������߻���һ������.\n",me);
                ob=new(__DIR__"creat");    
                ob->move(me);
                me->add_temp("mark/open_creat",1);
                return 1;
        }

	if(sizeof(filter_array(children(__DIR__"yxiao"),(: clonep :))) > 0 )
		return notify_fail("��������һ������,�ǿյ�.\n");

	message_vision("$N�������һ��ϣ��,��������,���ڷ�����Ҫ�ҵİ�����.\n",me);
	obj=new(__DIR__"yxiao.c");
	obj->move(me);
	return 1;
}

