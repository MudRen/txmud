// quest.h gaibang

// ��������

mixed s_quest = ({
	([
	"quest":"��",
	"begin_msg":"����������һ�⡺ؤ�����š�����ȥ�͸�����������ϡ�\n",
	"hint": "�����ϳ����ڻ������С�ƹ������ơ�\n",
	"pre_init": (: call_other, __FILE__, "give_xin" :),
	"end_msg":"���ã��ã����ĺܺá���\n",
	"name":"�����ϵĻ��š�",
	"reward" :25,
]),


});

// �м�����
mixed m_quest = ({

});

//�߼�����
mixed h_quest = ({

});


mapping query_quest(int exp, object me)
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


mapping give_xin(mapping qt, int exp)
{
	object me,xin;
	me = this_player();
	//map_delete(qt,"pre_init");

	if( !me )  return qt;

	xin = new("/d/obj/gaibang/shouxin");

	if( !xin->move(me) ) destruct(xin);

	return qt;
}
