// shidao3.c

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ��ɽ��С·��·�߳�������ݣ��Լ����������������
ӭ����һ��⻬��ʯ�ڡ�
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"shidao2",
]));
	set("outdoors","feiyu");
        setup();
}

void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
        object me = this_player();

	if(arg != "ʯ��" && arg !=  "wall")
		return notify_fail("��Ҫ����ʲô?\n");

	if(me->query("force") < 100)
		return notify_fail("���������û�е�Ϣ����,���������˹�.\n");

        if (me->query("kee") <100)
                return notify_fail("��̫����,��������Ϣһ�°�.\n");

        if (me->query("force_factor") < 100)
                return notify_fail("�㲻���������ǻ���������ʯ�ڵ�.\n");

	if(query("exits/enter"))
		return notify_fail("���ʯ���Ѿ����˻�����.\n");

        message_vision("$N���һ��,��������,����ʯ�ڻ�ȥ������\nֻ����һ������,ʯ�ڱ�������һ��ȱ�ڡ�\n$NҲ�۵�����������\n",me);

	me->receive_damage("kee",100,"tire");
        me->add("force",-100);

	set("exits/enter",__DIR__"shidao9");
	return 1;
}
