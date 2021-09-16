// quest.c
// 靖海任务

// 初级任务
mixed s_quest = ({
([
	"quest":"杀",
	"begin_msg":"有个混入我派的奸细『%s』最近事情败露出逃，你去把他追上杀了。",
	"hint": "据探报此人已逃往『%s』一带。",
	"pre_init": (: call_other, "/d/jinghai/quest/jianxi", "init_jianxi" :),
	"end_msg" : "好！辛苦你啦。",
	"name" : "%s",
	"reward" :100,
]),

});

// 中级任务
mixed m_quest = ({
	([
	"quest":"抓捕",
	"begin_msg":"最近到上有一个叫『%s』的犯人逃跑了，你去想办法抓回来交给无名岛牢房看守。",
	"hint": "外面的弟子有的说在『%s』一带好像见到过。",
	"pre_init": (: call_other, "/d/jinghai/quest/fanren", "init_fanren" :),
	"end_msg" : "好！辛苦你啦。",
	"name" : "%s",
	"reward" :200,
]),

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
