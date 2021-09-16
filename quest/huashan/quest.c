// quest.c
// ��ɽ����

inherit F_NATURE;

// ��������
mapping bian = ([
	"quest":"��",
	"begin_msg":"������鲻�࣬��ȥ��˫��Ь���ҡ�",
	"hint": "���Ь�Ĳ�ֻ�С����¡������ġ������ݡ���ã���ȥ
\t�ǰ�(ba)Щ�������ݡ������ϡ����졻�ڻ���
\t���ɺ󣬱�ɲ�Ь��",
	"end_msg" : "�ã�����������",
	"name" : "��Ь",
	"reward" :40,
]);

mapping zai = ([
	"quest":"����",
	"begin_msg":"�м����齻�������죬�������ҩ���Ի�󽻸��������ʡ����������ʡ�ס��
\t�������塻����ר��Ϊ������ֲ�ĵ��ӣ���ȥ�������塻�ġ�ҩ�
\t�������ɡ�ע���ҩ������������֮�أ�����������ֻ���������ֲ�
\t���ܳɻ��Ҫ�Ĺ����ҡ������ʡ��������ġ�",
	"hint": "�ڡ������塻�ġ�ҩ���ҩ���Ի�󽻸��������ʡ����������ʡ���
\t��ҩ�����ҩ������Ҫ�ġ����ߡ�ҲҪ�ҡ������ʡ�Ҫ��ҩ��
\tֻ�С����ϡ����ֲſ��ܳɻ",
	"pre_init": (: call_other, __FILE__, "give_miao" :),
	"end_msg" : "�ã��ɵò���",
	"name" : "ҩ��",
	"reward" :90,
]);

// �м�����
mixed m_quest = ({
	([
	"quest":"̽��",
	"begin_msg":"���������ɵ����Գ�����Ϊ���Σ���ǰ������������չ���ܡ�����͵����
����ҽ������Ҹ�Ů��������������ʿ�������ݣ���ȥ��̽��̽��Ϣ��һ��
����һ��ҪΪ�������",
	"hint": "��˵���������ڡ���ͬ����һ�����",
	"end_msg":"�ã�Ϊ��������������ŵ��ӵı�ɫ��",
	"name":"����չ���ܵ��ټ�",
        "reward" :120,
]),
});

//�߼�����
mixed h_quest = ({});

mapping query_quest(int exp, object me)
{
	mixed all;
	mapping q;
	int t = query_time();

	if((t >= 1230) || (t <= 360))
		all = ({ zai });
	else
		all = ({ bian });

	if(exp >= 500000)
		all += m_quest;
	if(exp >= 2000000)
		all += h_quest;

	q = all[random(sizeof(all))];

	if(!undefinedp(q["pre_init"]) && functionp(q["pre_init"]))
		q = evaluate(q["pre_init"],q,exp);

	return duplicate(q);
}

mapping give_miao(mapping qt, int exp)
{
	object me = this_player(), miao;

	//map_delete(qt,"pre_init");

	if(!me)
		return qt;

	miao = new("/d/huashan/obj/miao");

	if(!miao->move(me))
		destruct(miao);

	return qt;
}
