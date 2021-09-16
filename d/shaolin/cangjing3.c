// Room: /d/shaolin/cangjing3.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

private mixed *msg_strs = ({

// ��һ��
({
"�������⣬����ƽ������ǰ�ɱ����ơ�",
"�������ƣ���ָ���ϣ�������ԡ�",
"����Ĭ��ھ�����������ֱ�������ֵ��أ�������Խ����ĳ�ò�๧��",
	}),

// �ڶ���
({
"����̤ʵ����ϥ΢�ɣ���������ǰ������չ��",
"���ƣ��������⣬��Ŀǰ�ӣ������涯���������ߡ�",
"����Ĭ��ھ�����ָ�ҵأ�����ƽ������ƽ������"
	}),

// ������
({
"����ŵأ��������˫���Ͼٸ߹�ͷ����",
"���Ʊ�ȭ��ȭ����ǰ����֫��������ȭ��������������",
"����Ĭ��ھ���������в����ֲ��ҧ�����ز��ſ�����������£����ܵ�Ϣ���İ���",
	}),

// ������
({
"��ϥ�����ҽŸ��������³������鲽��",
"���ָ߾���ֱ���������£�ͷ΢��б��˫Ŀ���������ġ�",
"����Ĭ��ھ���ֻ�������Ƹ�ͷ����������ע˫�����Ƕ�����Ƶ��Ϣ��������������ٰ��",
	}),

// ������
({
"������ȭ������ǰ�Ϸ���˫Ŀ��ȭ��",
"������ȭ��������⣬б���ڱ���",
"�����ת�����󹭲��������ֽ�������",
"����Ĭ��ھ������Ⱥ���ǰ����С���������ɣ������������򣬹�ԭ��ע˫ͫ��",
	}),

// ������
({
"����ǰƽ�٣�������ǰ��ʮָ�����ֿ���������ԡ�",
"����ŭĿƽ��ǰ�������ƽŸ�����",
"����Ĭ��ھ���ͦ���ŭĿ��������ǰ�������ջش��������ߴ�ȫ��",
	}),

// ������
({
"�ż����Σ��������ɰ����Σ�������ǰ�ɲ���������ǰ��",
"�������⾭�����󣬳ɹ����������ָ�����ϡ�",
"����Ĭ��ھ����������ţ�������������ͷ�ջأ��������ͣ��������֣���ֱ������",
	}),

// �ڰ���
({
"���������һ������ϥ�¶׳�����",
"����ֱͦ�����ֲ����������ⷭ�����ϣ�С��ƽ����������״��",
"����Ĭ��ھ����������࣬������ע�����㿪���ƾᣬ�ְ������á�",
	}),

// �ھ���
({
"��������ǰ����̽����ָ��ɹ��֣�������ת��",
"������������ת������������֮��������ˮƽ��Ȧ��",
"����Ĭ��ھ�������̽צ������ҳ�����ʿЧ֮������ƽʵ��",
	}),

// ��ʮ��
({
"�ҽ����ҿ�һ�󲽣�����ϥ�¶ף����ҹ��������ơ�",
"����ǰ�㣬˫�ֳŵأ�ͷ΢̧��Ŀעǰ�·���",
"����Ĭ��ھ�������ֶ������㣬�����������������ͷ����̽ǰ�ƣ��ȱ���������ƽ��",
	}),

// ��ʮһ��
({
"˫�����ƻ��������Ҷ��ϣ������ϱ�ͷ�󲿣���ָ����С�Ժ�Ƭ�̡�",
"ֱϥ������������������ʹͷ̽��ϥ������״��",
"����Ĭ��ھ�����������ԣ�������ϥ�䣻ͷΩ̽���£��ڸ������أ�",
	}),

// ��ʮ����
({
"���ȿ�����˫����������ǰ�����Ͼ���ͷ����Ŀ���ƶ��ƣ�������ֱ��",
"ʮָ���棬���������У��������ϣ�����������",
"����ǰ����˫���´����������أ����׵�Ŀ��",
"����Ĭ��ھ�����ע���ģ�Ϣ���ڱǣ����������ʹ�ά����",
	}),
});

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��յ����Ĵ󷿼䣬�����������һ�ŵͰ���������
�����ϵ�����ֻ���������ܵ�ǽ����Ƕ�ż��顺ʯ�塻��ʯ��
�Ͽ��Ų��ٸ�����̬��С�ˣ����ϻ�����һЩ�ּ����м�һ��ʯ
����Ϸ���Ȼ���š��׽���������֣��������������������
ǰ������ (canwu) �׽�ĵط���������һ��Сľ�ţ���������
�������µ�Ҫ�أ�����ľ�����궼�����ŵģ������Ҫ��ȥ����
��(knock)�Ž��ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"cangjing2",
]));

	set(SAFE_ENV,1);
	setup();
	create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/cangjing_key");
}

void init()
{
	add_action("do_knock",({ "knock","qiao" }));
	add_action("do_canwu","canwu");
}

int do_knock(string arg)
{
	object room,hc;

	if(arg != "door" && arg != "��" && arg != "ľ��")
		return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$Ņ����ľ�����������˼��¡�\n",this_player());

	if(!room = find_object(__DIR__"cangjing2"))
		room = load_object(__DIR__"cangjing2");
	if(!room)
		return notify_fail("��������û��һ�㶯����\n");

	if(!objectp(hc = present("hui chi",room)))
		return notify_fail("��������û��һ�㶯����\n");

	hc->want_out();
	return 1;
}

int do_canwu(string arg)
{
	object me = this_player();
	mapping yjj;
	int qn;

	if(me->query("class") != "shaolin")
		return 0;

	if(arg != "ʯ��")
		return notify_fail("��Ҫ����ʲô��\n");

	if(!me->query("family/can_study_yijin"))
		return notify_fail("���������ѧ��������������ʯ���ϵ������޷���⡣\n");

	if(me->query("gin") < 250 || me->query("sen") < 250)
		return notify_fail("�����ھ���̫��޷����о�������������ѧ��Ҫ��\n");

	if(me->query("force") < 1200)
		return notify_fail("���������������޷��˹���\n");

	me->start_busy(120);

	if(!mapp(yjj = me->query("family/yijin-jing")))
		yjj = (["level":0,"step":0]);

	if(yjj["level"] >= 12)
	{
		me->stop_busy();
		return notify_fail("���Ѿ������׽������͸�����ڻ��ͨ�ˡ�\n");
	}

	if(yjj["level"] < 0)
		yjj["level"] = 0;

	qn = (yjj["level"] + 1)*(yjj["level"] + 1)*30;

	if( me->query("potential") - me->query("learned_points") < qn )
	{
		me->stop_busy();
		return notify_fail(sprintf("�����׽����%s�Ƶĵ�%s����Ҫ���� %d ��Ǳ�ܡ�\n",
			chinese_number(yjj["level"] + 1),chinese_number(yjj["step"] + 1),qn ));
	}

	me->receive_damage("gin",200,"tire");
	me->receive_damage("sen",200,"tire");
	me->add("force",-1000);
	me->add("learned_points",qn);

	call_out("do_begin",2,me,yjj);
	return 1;
}

private void do_begin(object me,mapping yjj)
{
	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	// ������
	message_vision("\n$Nͷ��ƽ��Ŀǰ�ӣ���΢�գ����ص���������ȫ��������������֮�Ѿ���\n\n",me);
	call_out("do_lasting",8,me,yjj,0);
}

private void do_lasting(object me,mapping yjj,int n)
{
	string *msg;

	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	if(yjj["level"] < 0 || yjj["level"] >= sizeof(msg_strs))
	{
		write("���ִ�������������ʦ���档\n");
		me->stop_busy();
		return;
	}

	msg = msg_strs[yjj["level"]];
	if(!sizeof(msg) || n < 0 || n >= sizeof(msg))
	{
		write("���ִ�������������ʦ���档\n");
		me->stop_busy();
		return;
	}

	message_vision(sprintf("\n$N%s\n\n",msg[n]),me);

	if( ++n >= sizeof(msg))
	{
		call_out("do_end",4,me,yjj);
		return;
	}

	call_out("do_lasting",8,me,yjj,n);
}

private void do_end(object me,mapping yjj)
{
	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	if( ++yjj["step"] >= 3)
	{
		yjj["level"]++;
		yjj["step"] = 0;

		if(yjj["level"] >= 12)
			tell_object(me,BWHT HIG"\n�㽫���׽����ȫ����͸�����ڻ��ͨ�ˡ�\n\
������ѧ�������Ϊ�Ӵ˽�����һ��ȫ�µľ��硣\n\n"NOR);
		else
		tell_object(me,sprintf(HIY"\n���Ѿ������׽���ĵ�%s�Ƴ��������ˣ������ѧ��Ϊ������һ���µľ��硣\n\n"NOR,
			chinese_number(yjj["level"]) ));
	}

	else
		tell_object(me,sprintf(HIY"\nͨ���Ե�%s�صĲ�����ԡ��׽���ĵ�%s�����˽�һ�����˽⡣\n\n"NOR,
			chinese_number(yjj["step"]),chinese_number(yjj["level"]+1) ));

	me->set("family/yijin-jing",yjj);
	tell_room(__FILE__,me->name()+"�й���ϣ�ƣ�͵Ĵ�����˫�֡�\n",({me}));
	me->stop_busy();
}
