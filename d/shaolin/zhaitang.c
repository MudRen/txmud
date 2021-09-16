// Room: /d/shaolin/zhaitang.c

inherit ROOM;

void create()
{
	set("short", "ի��");
	set("long", @LONG
�����������µ�ի�ã�����̵�ϰ�߹��粻ʳ��Ҳ������ʱ
֮ǰ����ʱ֮��ſ��ԳԶ����ģ���������һ����ͣ�������ʱ
���ǲ���������ġ���������ʱ�����ر�æµ����ͷɮ��æ����
��������Ȼ����ի�����Կ����ŵ���������㡣��ǽ����һ
�ڴ�ˮ�ף���Ҫ�ǿ��˿�������Ҩ(drink)ˮ�ȡ���������������
��Ժ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"w_court",
]));

	set("objects", ([
	__DIR__"npc/shaofan_seng" : 1,
]));

	setup();
}


void init()
{
	add_action("do_drink", "drink");
}

int do_drink(string arg)
{
	object me = this_player();

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
		return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
	me->add("water", 20);
	return 1;
}
