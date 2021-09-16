// quest.c

// 初级任务
mixed s_quest = ({
	([
	"quest":"找",
	"begin_msg":"最近药房配制新药需要一剂『百云汤』，此汤由『百实果』、『步云草』辅以\n\t『金银花』和『莲子』煎制而成，你快去弄来。",
	"hint": "莲子在『涵雨儿』那可能有，百实果、步云草和金银花可以在『百花圃』找到，找齐后\n      可以找『煎药女僮』煎制。\n",
	"end_msg":"好，这正是我要找的，谢谢你了！",
	"name":"百云汤",
	"reward" :70,
]),

([
	"quest":"巡查",
	"begin_msg":"没有什么别的事情，你去把前院东西走向的那条小路巡查一下吧。",
	"hint": "就是『绿绫』总管把守的那条小路。\n",
	"end_msg":"好，辛苦你了！",
	"name":"前院东西走向的小路",
	"pre_init": (: call_other, "/d/feiyu/quest/patrol", "init_user" :),
	"reward" :50,
]),

([
	"quest":"药苗圃",
	"begin_msg":"『药苗圃』的地好久没翻了，你去帮着翻一翻。",
	"hint": "『药苗圃』就在后门外面的小路边，药锄和水桶可以找『漫雨儿』要。\n",
	"end_msg":"好，辛苦你了！",
	"name":"翻地",
	"reward" :60,
]),

});

// 中级任务
mixed m_quest = ({


});

//高级任务
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
