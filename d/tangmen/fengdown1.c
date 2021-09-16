// Room: /d/tangmen/fengdown1.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
������ɽ�ȵĹȵף������ĵ�û��һ�����졣�����Ƕ��͵�
ɽ�ڸ������ƣ�ɽ��������һ���첲�ֵ�[����]�����洹������
LONG
	);

	set("item_desc", ([
	"����" : "����һ���첲�����ӣ�����������(climb)������ɽ���õġ�\n",
]));

	set("exits", ([
	"west" : __DIR__"fengdown2",
]));

	set("outdoors", "tangmen");
	setup();
}

void init()
{
	add_action("do_push", "climb");
}

int do_push(string arg)
{
	object me = this_player();

	if(arg != "����")
		return 0;

	if(find_call_out("arrive_up") != -1)
		return notify_fail("�����������������������أ���һ�����\n");

	me->start_busy(3);
	message_vision("$N�������ӻ�����������ȥ��\n", me);
	call_out("arrive_up", 2, me);

	return 1;
}

protected void arrive_up(object who)
{
	if(!who || (environment(who) != this_object()))
		return;

	who->move(__DIR__"feng");
}
