// jingshu.c

#define COUNT	3
inherit ITEM;

string *contents = ({
"�����ǡ�һʱ������Ϊ��ֻ�����¶�԰��",
"��ʱ�������𡣱���ӦΨȻ��",
"�����ӷ��š����˵�ǡ�����������˵��Ϊ�����С�",
"��˼Ω�����˷ֱ𷢼��������б������ʱ��",
"���������������������������˵��Ϊ�����С�",
"��˼Ω�����˷ֱ𷢼����������С�",
"�����б���Ӻ������ߡ�������������������",
"��Ϊ������������Ϊ���ߡ����о�����˵��",
"���б��𡣼������������������������������˵��",
"�������о�˼Ω�����˷ֱ𷢼��𸴸��������Ի��",
"����ۼ����߻����۷�����ػ۶�۲����ܼ����䱦���档",
"��������Ի�ܡ���������Ի����",
"����������ƽ˵��������Ի����Ϊ���˾�˵˼Ω�ܼ��ܿ������ֱܷ��ܼ���",
"������������������Ի���������й�����а�ܻ���",
"����Ի�������������Ŀ���������������",
"����Ի������ĸ����Ŀ����������ĸ������",
"��Ŀ�����������Ǿ��ߡ�����ԻĿ���������µ���Ϊ�����������ʡ�",
"����Ի����Ŀ��������Ϊͬѧ�ߡ�����������������",
"����˵���Ǵ����������ҡ���˼Ω�ڡ�ʱ��������Ի����Ϊ�������������ʡ�",
"��Ϊ˵�����С��ε�Ϊ�ġ�һΪ�ࡣ��Ϊϰ����Ϊ������Ϊ����",
"������������ࡣ�ε�Ϊ���߿��С������ࡣ���ϿࡣΪ��������ࡣ",
"�������ֿ��������߿���Ϊ�εȡ������˱˱����֡����������������������ɡ�",
"���������������ѵá�����Ϊ���������߿ࡣ",
"����Ե����Ϊ���ߡ��������йʸ��ࡣ�Ӹ�������",
"��ʹ��ʹ��������ࡣ�Ӹ����������ܸ��ܡ���������ࡣ",
"�Ӹ�������֪�ܸ��ܡ���������ա��Ӹ����������ܸ��ܡ�",
"�������ա��Ӹ�������֪�ܸ��ܡ����������ա��Ӹ�������",
"���ܿิ�ࡣ����ƣ���ա��Ӹ����������ܸ��ܡ�������ƣ���ȑn��",
"�Ӹ����������ܸ��ܡ�����������ƣ�������ա��Ӹ����������ܸ��ܡ�",
});

void create()
{
	string *names = ({"���Ͼ�","���Ͼ�","������","��ʮ���¾�","������","���о�","������","��ˮ��"});
	set_name("����", ({ "jing shu" }) );

	set_weight(100);

	if( clonep() )
	{
		set_default_object(__FILE__);
		set("name",names[random(sizeof(names))]);
		set("base_cname","����");
	}
	else
	{
		set("unit", "��");
		set("long", "����һ��������ϰ���ж�(chant)����ͨ��
�������ﶼ�ܼ����ľ��顣\n");
	}
	setup();
}

void init()
{
	add_action("do_chant","chant");
}

int do_chant(string arg)
{
	int lit_level;
	object me = this_player();

	if(environment() != me)
		return 0;

	if(me->is_busy())
		return notify_fail(BUSY_MESSAGE);

	if(!arg || !stringp(arg) || !id(arg))
		return notify_fail("��Ҫ�ж�ʲô��\n");

	if(me->is_fighting())
		return notify_fail(sprintf("����ս���޷������ж�%s��\n",name()));

	lit_level = me->query_skill("literate",1);
	if(!lit_level)
		return notify_fail(sprintf("������%s�����˷��ŷ���ԭ���Լ����ֲ�ʶһ����\n",name()));

	if(me->query("gin") <10)
		return notify_fail("�����ھ���̫���ˣ��޷��ж����ġ�\n");

	if(!me->query("is_bonze"))
		return notify_fail(sprintf("������%s��������ж���һ�������ʲôҲûŪ���ס�\n",name()));

	message_vision(sprintf("$N�ó�һ��%s������ж���������\n",name()),me);
	me->start_busy(10);
	call_out("continue_chant",2,me,1);
	return 1;
}

void continue_chant(object me,int n)
{
	remove_call_out("continue_chant");
	if(!objectp(me))
		return;
	write(sprintf("������ж���%s\n",contents[random(sizeof(contents))]));
	if(n >= COUNT)
	{
		call_out("finish_chant",2,me);
		return;
	}
	n++;
	call_out("continue_chant",2,me,n);
}


void finish_chant(object me)
{
	int lit_level,gin,improve;

	if(!objectp(me))
		return;

	gin = me->query("gin");
	lit_level = me->query_skill("literate",1);
        improve = (lit_level+me->query_int()*3)/4 + me->query_skill("chanting",1)/2 + me->query_skill("dacheng-fofa",1)/2;
	if(improve < 1)
		improve = 1;
	me->improve_skill("chanting",improve);
	message_vision(sprintf("$N���ա�%s��������С�ĵش����˻��\n",name()),me);
	me->receive_damage("gin",10);
	me->stop_busy();
	return;
}
