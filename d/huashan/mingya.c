// Room: /d/huashan/mingya.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�ɴ������ϣ������������ˡ����ߵ��������һ��������
��Ԩ����֪��·����˵���꺫���ߵ�����ŵþ���ʧ�룬����
д�����飬Ͷ����ȥ���������ϻ����С�����֮Ͷ�鴦�����֡�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"tianti1",
  "southdown" : __DIR__"yudao",
]));
        set("outdoors", "huashan");
	setup();
}

void init()
{
	add_action("do_ba", "ba");
}

int do_ba(string arg)
{
	object me = this_player(), grass;

	if( (me->query("class") != "huashan")
	|| (me->query("quest/huashan_quest/name") != "��Ь")
	|| (me->query("quest/huashan_quest/num") >=2)
	|| (time() - me->query("quest_fail_time") < 120) )
		return notify_fail("����������ϸ�����ң�û������Щ�ǡ������ݡ���\n");

	grass = new(__DIR__"obj/hl_grass");

	if(!grass->move(me))
	{
		destruct(grass);
		return notify_fail("�����ϷŲ����ٶ�Ķ����ˡ�\n");
	}

	grass->set_master(me->query("id"));

	me->add("quest/huashan_quest/num",1);
	message_vision("$N��ϸ�ı�����һ�£���ϸ�İ�����һС�ѡ������ݡ���\n",me);
	return 1;
}