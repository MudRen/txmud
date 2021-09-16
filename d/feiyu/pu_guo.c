// Room: /wiz/find/huapu/pu.c
// ��ժ��ʵ����

inherit ROOM;

int p = 5;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ���޴�Ļ��ԣ��������ļ����������ɫ���ʻ�����
˵�������ֻ�����ŵ������������ɩ����ά�������������
Ҳ�������������ͻ�ɢ�ġ�·�ߵ�С��ľ���еĻ����Ź�ʵ(guo)��
LONG
	);

	set("item_desc",([
	"��ʵ" : "��������ժ(zhai)������������\n",
	"guo" : "��������ժ(zhai)������������\n",
]));

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_pick","zhai");
}

int do_pick(string arg)
{
	object me = this_player(),ob;
	string *get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("��İ�ʵ���Ѿ���ժ���ˡ�\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "������")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("��ʵ��",get) == -1) ) )
	{
		message_vision("$NС�������·�ߵĹ�ľ��ժ��һö��ʵ����\n",me);
		ob = new(__DIR__"obj/baishi_guo");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"��ʵ��"});
		else
			get += ({"��ʵ��"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"���Ѿ��ɵ��˰�ʵ����"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"��������ԭ�����Ѿ����룬����ȥ��ҩ�ˡ�"));
		return 1;
	}


	message_vision("$N�ڹ�ľ���������ң�û��������Ĺ�ʵ��\n",me);
	return 1;
}
