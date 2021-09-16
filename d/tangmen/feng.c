// Room: /d/tangmen/feng.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����ͺͺ��ɽ�壬������������ȥ�����ƻֺ����
�ұ������۵ף�����ʮ���ɸߵĶ���ʯ�ڡ�������һ��ʯͷ���̣�
����˩��һ���첲�ֵ�[����]�������档
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"shangpo5",
]));

	set("item_desc", ([
	"����" : "����һ���첲�����ӣ�����������(climb)������ɽ���õġ�\n",
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

	if(find_call_out("arrive_down") != -1)
		return notify_fail("�����������������������أ���һ�����\n");

	me->start_busy(3);
	message_vision("$N�������ӻ�����������ȥ��\n", me);
	call_out("arrive_down", 2, me);

	return 1;
}

protected void arrive_down(object who)
{
	if(!who || (environment(who) != this_object()))
		return;

	who->move(__DIR__"fengdown1");
}
