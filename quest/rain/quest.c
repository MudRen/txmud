// quest.c

// ��������
mixed s_quest = ({
	([
	"quest":"��",
	"begin_msg":"���ҩ��������ҩ��Ҫһ�������������������ɡ���ʵ�����������Ʋݡ�����\n\t�����������͡����ӡ����ƶ��ɣ����ȥŪ����",
	"hint": "�����ڡ���������ǿ����У���ʵ�������Ʋݺͽ����������ڡ��ٻ��ԡ��ҵ��������\n      �����ҡ���ҩŮ�ס����ơ�\n",
	"end_msg":"�ã���������Ҫ�ҵģ�лл���ˣ�",
	"name":"������",
	"reward" :70,
]),

([
	"quest":"Ѳ��",
	"begin_msg":"û��ʲô������飬��ȥ��ǰԺ�������������С·Ѳ��һ�°ɡ�",
	"hint": "���ǡ���籡��ܹܰ��ص�����С·��\n",
	"end_msg":"�ã��������ˣ�",
	"name":"ǰԺ���������С·",
	"pre_init": (: call_other, "/d/feiyu/quest/patrol", "init_user" :),
	"reward" :50,
]),

([
	"quest":"ҩ����",
	"begin_msg":"��ҩ���ԡ��ĵغþ�û���ˣ���ȥ���ŷ�һ����",
	"hint": "��ҩ���ԡ����ں��������С·�ߣ�ҩ����ˮͰ�����ҡ��������Ҫ��\n",
	"end_msg":"�ã��������ˣ�",
	"name":"����",
	"reward" :60,
]),

});

// �м�����
mixed m_quest = ({


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
