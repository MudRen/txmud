// Room: chengxf8.c

inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�����ǳ���ة�ฮ�ĳ�����һ�����������һ����ζ������
�ĳ�ʦ�����Ǵӳ������¥�����ģ�������һ���Ż������С
�������ŷ��䣬�����������������߷���һ����ˮ�ס�
LONG
	);

	set("all_water",200);

        set("exits", ([
  "east" : __DIR__"chengxf6",
]));

	set("objects",([
	__DIR__"npc/chu_zi" : 1,
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

	if(query("all_water") <= 0)
		return notify_fail("ˮ����һ��ˮҲû���ˡ�\n");

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("���Ѿ���Ҳ�Ȳ���һ��ˮ�ˡ�\n");

	message_vision("$N��ˮ�ױ��ñ���Ҩ��ˮ���˼��ڡ�\n", me);
	me->add("water", 20);
	add("all_water",-1);
	if(query("all_water") <= 0)
		return notify_fail("ˮ���Ѿ�������ȸ��ˡ�\n");
	return 1;
}
