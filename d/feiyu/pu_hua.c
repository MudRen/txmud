// Room: /wiz/find/huapu/pu.c
// �ɲɽ�������

inherit ROOM;

int p = 5;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ���޴�Ļ��ԣ��������ļ����������ɫ���ʻ�����
˵�������ֻ�����ŵ������������ɩ����ά�������������
Ҳ�������������ͻ�ɢ�ġ��������������ʯ�̾͵�С������
�����ܿ��ŵĸ�ɫ�����������Ŀ����������������ֲ�(pick)һ
�����š�
LONG
	);

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object me = this_player(),ob;
	string *color = ({ "��","��","��","��","��" }),*get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("��Ľ������Ѿ����ɹ��ˡ�\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "������")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("������",get) == -1) ) )
	{
		message_vision("$NС��������ڻ�����ժ��һ���������\n",me);
		ob = new(__DIR__"obj/jinyin_hua");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"������"});
		else
			get += ({"������"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"���Ѿ�ժ���˽�������"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"��������ԭ�����Ѿ����룬����ȥ��ҩ�ˡ�"));
		return 1;
	}


	message_vision(sprintf("$N�����򻨴�����ժһ��С%s����ûС�ı�������һ�£��Ͻ��������˻�����\n",
		color[random(sizeof(color))]),me);
	return 1;
}
