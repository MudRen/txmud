//yaotian1
#include <ansi.h>
inherit ROOM;

int do_zhao(string arg);

// Room: /d/tangmen/yaopu1.c

inherit ROOM;

void create()
{
        set("short", "ҩ��");
        set("long", @LONG
������һ���ܴ��ҩ���ԣ���ؿ��Ÿ�ɫ�����С��������
��������������ӵĹ�ζ����
LONG
        );
        set("exits", ([
  "north" : __DIR__"yaopu1",
  "west" : __DIR__"yaopu4",
  "south" : __DIR__"yaopu9",
  "east" : __DIR__"yaopu6",
]));

        set("outdoors", "tangmen");
        set("yao", 5);

        setup();
        replace_program(ROOM);
}

void init()
{
	add_action("do_zhao","zhao");
}

int do_zhao(string arg)
{
        object me;
        int jingli_cost;

        me = this_player();
        jingli_cost = (-1) * (5 + random(15));

        if ( !arg || ( arg != "yao" ) )
                return notify_fail("�����ʲô��\n");

        if ( me->query_temp("find") )
                return notify_fail("���Ѿ��ҵ���һ���ҩ�����Խ����ˣ�\n");

	if ( me->query("jingli") <= ( - jingli_cost ) )
		return notify_fail("��̫ƣ���ˣ�û�о�������ҩ�ˡ�\n");

	if ( (int)query("yao") >= 1 )
        {
		message_vision(YEL"$N����������С���������ڻ�����Ѱ����ҩ�ݡ�\n"NOR, me);
		if ( random(1 + me->query("kar") - 10 ) >= 3 )
		{
			message_vision(HIG"$N���ϵĲ����Ż����еĲ�ҩ�������ҵ���һ�ꡣ\n$N������ҩ��С�ĵ����ڻ��С�\n"NOR, me);
			new(__DIR__"obj/caoyao")->move(me);
			me->set_temp("find",1);
		}

	        me->add("jingli", jingli_cost);
		add("yao",-1);
        }
	else
                return notify_fail("���ﶼ�Ѿ��������ˣ�û��ʲô���ҵ��ˡ�\n");

        return 1;
}