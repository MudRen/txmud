// quest.c


// 初级任务

mixed s_quest = (
{

	([
	"quest":"找",   "begin_msg":"最近正在研制一种能使人麻痹的药方需要一颗『海松子』你去找来。","hint": "此物一般生长在深山幽谷之中，很是难得，如果实在采不到，可以去成都打听打听，\n\t千万不要自己偷嘴吃了！\n",

	"end_msg":"好，正是这个东西，干得不错！",
	
        "name":"海松子",
	"reward" :70,
]),

}
);


// 中级任务

mixed m_quest = (
{

	([
	"quest":"找",
	"begin_msg":"最近咽喉疼得厉害，你去帮我找点『无花果』来治治我的嗓子。",
	"hint": "『无花果』原产在云南，蜀中很是难得，附近只听说成都的陆员外\n\t家后院有一个无花果树，你去想想办法。\n",
	
        "end_msg":"好，这正是我要找的，这可要谢谢你了！",
	"name":"无花果干",
	"reward" :120,
]),
}
);


//高级任务
mixed h_quest = ({});


mapping query_quest(int exp)

{
	mixed all;


	all = s_quest;


	if(exp >= 500000)

		all += m_quest;

	if(exp >= 2000000)

		all += h_quest;


	return copy(all[random(sizeof(all))]);

}
