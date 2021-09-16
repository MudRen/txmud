// quest_npc.c

#include <ansi.h>
inherit NPC;

int ask_quest(object me);
protected void give_reward(object me,mapping quest);
protected string qfile;
protected object qob;

protected void load_quest_object()
{
	if(!query("class"))
		error("�������� NPC �����趨���ɵ� class��\n");

	qfile = sprintf(QUEST_DIR"%s/quest",query("class"));
	if( file_size(qfile+".c") <= 0 )
		return;
	if(!objectp(qob = find_object(qfile)) && !objectp(qob = load_object(qfile)))
		return;
}

void setup()
{
	set("inquiry/quest", (: ask_quest :) );
	::setup();
	load_quest_object();
}

int ask_quest(object me)
{
	int exp;
	mapping quest;
	string clas;

	if(!me
	|| !(clas = me->query("class"))
	|| ( clas != query("class")))
		return 0;

	exp = me->query("combat_exp");
	if(exp < 20000)
	{
		write(sprintf(CYN"%sЦЦ˵��������ʦ�ž���Ϊʦ��Ч��������ɼΣ�����������ȥ��û�����˵�ɡ�\n"NOR,
			name()));
		return 1;
	}

	// ǰ����δ���
	if(mapp(quest = me->query(sprintf("quest/%s_quest",clas))))
	{
		//me->add("family/gongji",-quest["reward"]/2);
		me->add("family/gongji",-quest["reward"]);
		me->delete(sprintf("quest/%s_quest",clas));
                me->set("quest_fail_time",time());
		write(sprintf("%s˵��������%s�����������������á�",name(), me->name()));
	}

	if(!objectp(qob))
	{
		load_quest_object();
		if(!objectp(qob))
			return notify_fail("����ûʲô���������\n");
	}

	quest = qob->query_quest(exp);
	if(!quest || !sizeof(quest))
		return notify_fail("\n�����ɵ�����ϵͳ�����⣬������ʦ���档\n\n");

	write(sprintf("%s˵�� %s", name(), quest["begin_msg"]));
	write(sprintf("%s˵�� %s", name(), quest["hint"]));

	map_delete(quest,"begin_msg");
	me->set(sprintf("quest/%s_quest",clas),quest);

	return 1;
}

nomask int accept_object(object me,object ob)
{
	mapping quest;
	string clas;

	if(!me
	|| !(clas = me->query("class"))
	|| ( clas != query("class")))
		return 0;

	if(!mapp(quest = me->query(sprintf("quest/%s_quest",clas))))
		return 0;

	if( (quest["quest"] != "��") && (quest["quest"] != "��") )
		return 0;

	if((ob->query("name") != quest["name"]) || userp(ob))
	{
		write(sprintf(CYN"%s˵������������ȥ��%s�����ⶫ������������ʲô����\n"NOR,
			name(),quest["name"]));
		return 0;
	}

	if(function_exists("check_quest_giver", ob)
	&& !ob->check_quest_giver(me))
			return 0;

	give_reward(me,quest);

	me->delete(sprintf("quest/%s_quest",clas));
	call_out("do_dest",1);
	return 1;
}

protected void give_reward(object me,mapping quest)
{
	int reward_qn,reward_exp,reward;

	if(!me)
		return;

	tell_object(me,sprintf(CYN"%s΢Ц��ͷ˵������%s��\n"NOR,name(),quest["end_msg"]));

	reward = quest["reward"];

	if(reward < 40)
		reward = 40;

	//me->add("family/gongji",reward);
	me->add_shimen_gongji(reward);

	if(me->query("family/gongji") < -5000)
	{
		tell_object(me,sprintf("��Ϊʦ�ű����гɣ��������ˣ�\n %3d ��ʦ�Ź���\n\n",reward));
		return;
	}

	reward_qn = reward/4 + random(reward/4);
	reward_exp = reward/4 + random(reward/4);

	tell_object(me,sprintf("��Ϊʦ�ű����гɣ��������ˣ�\n %3d ��Ǳ��\n %3d �㾭��\n %3d ��ʦ�Ź���\n\n",
		reward_qn,reward_exp,reward));

	me->add("potential",reward_qn);
	me->add("combat_exp",reward_exp);
	me->delete("quest_fail_time");
}

protected void do_dest()
{
	object *obs;

	obs = all_inventory(this_object()) - ({0});

	if(!arrayp(obs) || !sizeof(obs))
		return;

	obs = filter_array(obs,(: !$1->query("equipped") :));

	if(sizeof(obs))
		foreach(object ob in obs)
			destruct(ob);
}

void init()
{
	string clas;

	if( previous_object()
	&& userp(previous_object())
	&& (clas = previous_object()->query("class"))
	&& clas == query("class"))
	{
		call_out("check_quest",1,previous_object());
	}
}

protected void check_quest(object me)
{
	string clas;
	mapping quest;

	if( !me
	|| !living(me)
	|| environment(me) != environment()
	|| !(clas = me->query("class"))
	|| ( clas != query("class")) )
		return;

	if( !mapp(quest = me->query(sprintf("quest/%s_quest",clas))) )
		return;

	if( quest["quest"] == "��")
		return;

	if((quest["quest"] == "ɱ") && !quest["killed"])
		return;

	if( (quest["quest"] != "ɱ") && !quest["finish"])
		return;

	give_reward(me,quest);

	me->delete(sprintf("quest/%s_quest",clas));
}
