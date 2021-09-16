// Room: /u/w/wangs/a/yu72.c

inherit ROOM;

void create()
{
	set("short", "���µ�");
	set("long", @LONG
�����ǰ��һ����ֱ��ɽ�壬����ǧ�ɣ��嶥��������
��Լ�ɼ���ɽ���ͺͺ�ģ����������㴦�����Ѿ��ߵ�����
�׵ľ�ͷ��ֻ��һƬ��ľ���������ǰ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu69",
]));
        set("item_desc",([
        "��ľ" : "һƬŨ�ܵĹ�ľ�֣���Լ���ܿ���һС�����б����������ĺۼ���\n",
        "wood" : "һƬŨ�ܵĹ�ľ�֣���Լ���ܿ���һС�����б����������ĺۼ�����\n",
]));
	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	object me,ob,obj;

	me = this_player();

	if(arg != "��ľ" && arg !="wood")
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}

	if(!obj = me->query_temp("weapon"))
	{
		write("��Ҫ��ʲô����\n");
		return 1;
	}

	if( (me->query("class") == "rain") && (random(20) > me->query("kar")) )
	{
		ob=new(__DIR__"obj/fengyuesword");
		if(!ob->valid_clone())
			destruct(ob);
			
		else
		{
			ob->move(this_object());
			message_vision("$N���Ź�ľ�ַ�����ȥ���о�������һ��Ӳ���Ķ�����\n��ϸһ����������һ�ѷ����ı�����\n",me);
			return 1;
		}
	}
	message_vision("$N���Ź�ľ�ַ�����ȥ�����������һƬ��ľ��\n",me);
	me->start_busy(2);
	return 1;
}
