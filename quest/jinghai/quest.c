// quest.c
// ��������

// ��������
mixed s_quest = ({
([
	"quest":"ɱ",
	"begin_msg":"�и��������ɵļ�ϸ��%s����������¶���ӣ���ȥ����׷��ɱ�ˡ�",
	"hint": "��̽��������������%s��һ����",
	"pre_init": (: call_other, "/d/jinghai/quest/jianxi", "init_jianxi" :),
	"end_msg" : "�ã�����������",
	"name" : "%s",
	"reward" :100,
]),

});

// �м�����
mixed m_quest = ({
	([
	"quest":"ץ��",
	"begin_msg":"���������һ���С�%s���ķ��������ˣ���ȥ��취ץ���������������η����ء�",
	"hint": "����ĵ����е�˵�ڡ�%s��һ�������������",
	"pre_init": (: call_other, "/d/jinghai/quest/fanren", "init_fanren" :),
	"end_msg" : "�ã�����������",
	"name" : "%s",
	"reward" :200,
]),

});

//�߼�����
mixed h_quest = ({});

mapping query_quest(int exp)
{
	mixed all;
	mapping q;


	all = s_quest;

	if(exp >= 500000)
		all += m_quest;
	if(exp >= 2000000)
		all += h_quest;

	q = all[random(sizeof(all))];

	if(!undefinedp(q["pre_init"]) && functionp(q["pre_init"]))
		q = evaluate(q["pre_init"],q,exp);

	return duplicate(q);
}
