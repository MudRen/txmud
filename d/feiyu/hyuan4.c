// This is a room made by roommaker.

inherit ROOM;

private int have = 6;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
����һ��С��԰����˵��԰����ȴ�����˽в������ֵ���
�������������ޣ������˱ǣ����м���С�ϻ�������Ŀ����԰��
�����ľ�ܣ�ľ����������������
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hyuan3",
  "west" : __DIR__"hyuan5",
]));
	set("outdoors","feiyu");
        setup();
}

void init()
{
	add_action("do_pick",({ "pick","zhai" }));
}

int do_pick(string arg)
{
        object me = this_player(),ob;

	if(arg != "С�ϻ�" )
		return notify_fail("��Ҫժʲô��\n");

	if(!have)
		return notify_fail("С�ϻ�����ժû�ˡ�\n");

        if (!me->query_temp("pickhu"))
        {
                message_vision("$N�����ժ����һ��С�ϻ���\n",me);
                me->set_temp("pickhu",1);
                have--;
                ob=new(__DIR__"obj/zflower");
                ob->move(me);
                return 1;
        }
        return notify_fail ("���Ѿ�ժ��һ��С�ϻ��ˡ�\n");
}
