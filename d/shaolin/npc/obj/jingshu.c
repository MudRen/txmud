// jingshu.c

#define COUNT	3
inherit ITEM;

string *contents = ({
"闻如是。一时佛在舍为国只树给孤独园。",
"是时佛告诸比丘。比丘应唯然。",
"比丘便从佛闻。佛便说是。比丘真正法说。为是四谛。",
"具思惟见开了分别发见。若所有比丘过世时。",
"从如来无所著正觉。是亦从是正说。为是四谛。",
"具思惟见开了分别发见。从是四谛。",
"若所有比丘从后世来者。从如来无所著正觉。",
"是为从是正法。真为贤者。四谛具如上说。",
"今有比丘。见在如来无所著正觉。是亦从是正谛说。",
"如是四谛具思惟见开了分别发见佛复告比丘舍利曰。",
"比丘慧疾慧走慧利慧方慧深徹慧恶慧不厌能见慧珍宝慧随。",
"比丘舍利曰能。比丘舍利曰所。",
"是贤者四谛平说具能舍利曰比丘为奇人具说思惟能见能开能了能分别发能见。",
"今多少随道法。是舍利曰比丘。最无有过。从邪能还。",
"舍利曰比丘。能令随道。目建连比丘能令竟道。",
"舍利曰比丘如母生。目建连比丘如母供养。",
"当目建连比丘如是觉者。舍利曰目建连当可事当。为供当。可往问。",
"舍利曰比丘。目建连比丘。为同学者。致乐念令无有他。",
"佛已说如是从坐起入寺室。倾思惟在。时贤者舍利曰比丘。为利故令佛在世间故。",
"今为说是四谛。何等为四。一为苦。二为习。三为尽。四为道。",
"四谛受行令灭苦。何等为贤者苦谛。从生苦。从老苦。为不得是亦苦。",
"仓卒五种苦生。贤者苦生为何等。若是人彼彼人种。从生增生。以随以有欲成。",
"五阴已生。命根已得。是名为生。生贤者苦。",
"何因缘生苦为生者。人令身有故更苦。从更复更。",
"从痛复痛。令意更苦。从更复更。从受复受。令身意更苦。",
"从更复更。知受复受。令身待受恼。从更复更。觉受复受。",
"意念热恼。从更复更。知受复受。令身意热恼。从更复更。",
"从受苦复苦。身热疲热恼。从更复更。从受复受。意热恼疲令热憂。",
"从更复更。从受复受。令身意恼热疲从念热恼。从更复更。从受复受。",
});

void create()
{
	string *names = ({"楞严经","华严经","法华经","四十二章经","清心咒","四谛经","法海经","恒水经"});
	set_name("经书", ({ "jing shu" }) );

	set_weight(100);

	if( clonep() )
	{
		set_default_object(__FILE__);
		set("name",names[random(sizeof(names))]);
		set("base_cname","经书");
	}
	else
	{
		set("unit", "本");
		set("long", "这是一本和尚修习佛法诵读(chant)的普通佛
家寺庙里都能见到的经书。\n");
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
		return notify_fail("你要诵读什么？\n");

	if(me->is_fighting())
		return notify_fail(sprintf("正在战斗无法安心研读%s。\n",name()));

	lit_level = me->query_skill("literate",1);
	if(!lit_level)
		return notify_fail(sprintf("你拿起《%s》翻了翻才发现原来自己大字不识一个。\n",name()));

	if(me->query("gin") <10)
		return notify_fail("你现在精力太差了，无法诵读经文。\n");

	if(!me->query("is_bonze"))
		return notify_fail(sprintf("你拿起《%s》认真地诵读了一番，结果什么也没弄明白。\n",name()));

	message_vision(sprintf("$N拿出一本%s认真地诵读了起来。\n",name()),me);
	me->start_busy(10);
	call_out("continue_chant",2,me,1);
	return 1;
}

void continue_chant(object me,int n)
{
	remove_call_out("continue_chant");
	if(!objectp(me))
		return;
	write(sprintf("你低声诵读：%s\n",contents[random(sizeof(contents))]));
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
	message_vision(sprintf("$N读罢《%s》将经书小心地揣在了怀里。\n",name()),me);
	me->receive_damage("gin",10);
	me->stop_busy();
	return;
}
