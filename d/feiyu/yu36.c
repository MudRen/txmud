// Room: /u/w/wangs/a/yu36.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������һ�����ң����м����һ�Ŵ�(bed)��
��֪ƽʱ����λ���ס��������������Ӷ���ʰ�øɸ�
�������������롣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yu35",
]));
        set("item_desc",([
        "bed" : "һ�źܴ��ľ����\n",
        "��" : "һ�źܴ��ľ����\n",
]));

	setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me = this_player(),ob;

	if(arg != "��" && arg != "bed")
		return notify_fail("��ҪŲʲô��\n");

	if(!me->query_temp("mark/louth_quxiao"))
		return notify_fail("��ʹ��Ų��Ųľ��,����û��Ų����\n");

        if(sizeof(filter_array(children(__DIR__"obj/creat"),(: clonep :))) > 0)
                return notify_fail("��Ų����ľ��,ʲô��û����.\n");

	message_vision("$N��ľ��Ų����һ�ߣ����ִ�����һ��ľͷ����,$N�Ͻ���������.\n",me);
	ob = new(__DIR__"obj/creat");
	ob->move(me);
	me->delete_temp("mark/louth_quxiao");
	return 1;
}

