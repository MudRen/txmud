// This is a room made by roommaker.

inherit ROOM;

private int have = 6;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
����һ��С��԰����˵��԰����ȴ�����˽в������ֵ���
�������������ޣ������˱ǣ����м���С�׻�������Ŀ����԰��
�����ľ�ܣ�ľ����������������
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hyuan2",
  "west" : __DIR__"shidao9",
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

	if(arg != "С�׻�" )
		return notify_fail("��Ҫժʲô��\n");

        if(!have)
		return notify_fail("С�׻�����ժû�ˡ�\n");

        if (!me->query_temp("pickbai"))
        {
		message_vision("$N�����ժ����һ��С�׻���\n",me);
		me->set_temp("pickbai",1);
                have--;
                ob=new(__DIR__"obj/bflower");
                ob->move(me);
                return 1;
        }
	return notify_fail ("���Ѿ�ժ��һ��С�׻��ˡ�\n");
}
