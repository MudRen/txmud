// quest.c
// 华山任务

inherit F_NATURE;

// 初级任务
mapping bian = ([
	"quest":"编",
	"begin_msg":"最近事情不多，你去编双草鞋给我。",
	"hint": "编草鞋的草只有『明崖』附近的『呼啦草』最好，你去
\t那拔(ba)些『呼啦草』，赶上『晴天』在户外
\t晾干后，编成草鞋。",
	"end_msg" : "好！辛苦你啦。",
	"name" : "草鞋",
	"reward" :40,
]);

mapping zai = ([
	"quest":"栽种",
	"begin_msg":"有件事情交给你来办，你把这株药苗栽活后交给『万明仁』，『万明仁』住在
\t『华阴村』，是专门为我派培植的弟子，你去『华阴村』的『药田』
\t找他即可。注意此药材生长于阴寒之地，在咱们这里只有晚上栽种才
\t可能成活，需要的工具找『万明仁』他会给你的。",
	"hint": "在『华阴村』的『药田』将药苗栽活后交给『万明仁』，『万明仁』在
\t『药田』，栽药苗所需要的『工具』也要找『万明仁』要。药苗
\t只有『晚上』栽种才可能成活。",
	"pre_init": (: call_other, __FILE__, "give_miao" :),
	"end_msg" : "好！干得不错！",
	"name" : "药苗",
	"reward" :90,
]);

// 中级任务
mixed m_quest = ({
	([
	"quest":"探查",
	"begin_msg":"我名门正派弟子以出恶安良为己任，日前打听到飞贼『展飞熊』不但偷盗财
物，而且劫掠良家妇女，此人我正派侠士决不能容！你去打探打探消息，一有
机会一定要为民除害！",
	"hint": "听说此贼近日在『大同府』一带活动。",
	"end_msg":"好！为民除害正是我名门弟子的本色！",
	"name":"飞贼展飞熊的踪迹",
        "reward" :120,
]),
});

//高级任务
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
