// This is a room made by roommaker.

inherit ROOM;

private int have = 6;

void create()
{
        set("short", "С��԰");
        set("long", @LONG
����һ��С��԰����˵��԰����ȴ�����˽в������ֵ���
�������������ޣ������˱ǣ����м���С�컨������Ŀ����԰��
�����ľ�ܣ�ľ����������������
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hyuan4",
  "south" : __DIR__"hyuan2",
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

	if(arg != "С�컨" )
		return notify_fail("��Ҫժʲô��\n");

	if(!have)
		return notify_fail("С�컨����ժû�ˡ�\n");

        if (!me->query_temp("pickh"))
        {
                message_vision("$N�����ժ����һ��С�컨��\n",me);
                me->set_temp("pickh",1);
                have--;
                ob=new(__DIR__"obj/hflower");
                ob->move(me);
                return 1;
        }
        return notify_fail ("���Ѿ�ժ��һ��С�컨�ˡ�\n");
}
