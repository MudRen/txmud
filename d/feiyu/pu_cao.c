// Room: /wiz/find/huapu/pu_cao.c
// �ɲɲ��Ʋݡ�

inherit ROOM;

int p = 5;

void create()
{
	set("short", "�ٻ���");
	set("long", @LONG
����һ���޴�Ļ��ԣ��������ļ����������ɫ���ʻ�����
˵�������ֻ�����ŵ������������ɩ����ά�������������
Ҳ�������������ͻ�ɢ�ġ���ʯ�̾͵�С�����ϳ������(grass)��
LONG
	);

	set("item_desc",([
	"���" : "��Щ�ط��Ĳ���Ȼ���˰�(ba)����\n",
	"grass" : "��Щ�ط��Ĳ���Ȼ���˰�(ba)����\n",
]));

	set("outdoors","feiyu");

	setup();
}

void init()
{
	add_action("do_ba","ba");
}

int do_ba(string arg)
{
	object me = this_player(),ob;
	string *get;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!p)
		return notify_fail("��Ĳ��Ʋ��Ѿ����ι��ˡ�\n");

	me->start_busy(1);

	p--;

	if( (me->query("quest/rain_quest/name") == "������")
	&& ( !(get = me->query("quest/rain_quest/geted"))
	|| !sizeof(get)
	|| (member_array("���Ʋ�",get) == -1) ) )
	{
		message_vision("$N��·�ߵĲݴ���γ�һ�Ų��Ʋݡ�\n",me);
		ob = new(__DIR__"obj/buyun_cao");
		if(!ob->move(me))
			ob->move(environment(me));
		if(!arrayp(get))
			get = ({"���Ʋ�"});
		else
			get += ({"���Ʋ�"});
		me->set("quest/rain_quest/geted",get);
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"���Ѿ��ҵ��˲��Ʋݡ�"));
		if(sizeof(get) >= 4)
		me->add("quest/rain_quest/hint",sprintf("      %s\n",
			"��������ԭ�����Ѿ����룬����ȥ��ҩ�ˡ�"));
		return 1;
	}


	write("��������·�ߵĲݴ�������˼��£����ֶ���һЩ��ͨ����ݡ�\n");
	return 1;
}
