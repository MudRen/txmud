// quest.h gaibang

// 初级任务

mixed s_quest = ({
	([
	"quest":"找",
	"begin_msg":"：我这里有一封『丐帮手信』。你去送给华阴村的马长老。\n",
	"hint": "：马长老常常在华阴村的小酒馆里饮酒。\n",
	"pre_init": (: call_other, __FILE__, "give_xin" :),
	"end_msg":"：好，好，作的很好。！\n",
	"name":"『马长老的回信』",
	"reward" :25,
]),


});

// 中级任务
mixed m_quest = ({

});

//高级任务
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
