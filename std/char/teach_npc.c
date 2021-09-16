// teach_npc.c

#include <ansi.h>

private string *skill;

string *query_s() { return skill;}

nomask int set_valid_skill(string *ski)
{
	if(!ski || !arrayp(ski) || !sizeof(ski))
		return 0;

	foreach(string s in ski)
		if(!this_object()->query_skill(s,1))
			return 0;

	skill = ski;
	return 1;
}

nomask int accept_object(object who, object ob)
{
	int value,n;

	if(!is_money(ob) || !who || !userp(who))
		return 0;

	value = ob->value();

	n = who->query(sprintf("pay_teach/%s",replace_string(base_name(this_object()),"/","_")));
	n += value;
	who->set(sprintf("pay_teach/%s",replace_string(base_name(this_object()),"/","_")),n);
	return 1;
}

nomask int prevent_learn(object me, string arg)
{
	int paid,value;

	if(!skill || !arrayp(skill) || (member_array(arg,skill) == -1))
		return 0;

	if(me->query_skill(arg,1) >= this_object()->query_skill(arg,1))
		return notify_fail(sprintf(CYN"%sҡҡͷ˵��������%s����Ϊ���Ѿ�ûʲô�ý����ˡ�\n"NOR,
			this_object()->name(),to_chinese(arg)));

	paid = me->query(sprintf("pay_teach/%s",replace_string(base_name(this_object()),"/","_")));

	value = me->query_skill(arg,1);

	if(!value)
		value = 1;

	value++;
	if(paid < value*100)
		return notify_fail(sprintf(CYN"%s˵������Ҫѧϰ��%s������Ҫ������%s�����ӡ���\n"NOR,
			this_object()->name(),to_chinese(arg),chinese_number(value)));

	paid -= value*100;
	me->set(sprintf("pay_teach/%s",replace_string(base_name(this_object()),"/","_")),paid);
	return 1;
}

int recognize_apprentice(object ob)
{
	if(objectp(ob) && userp(ob))
		return 1;
	else
		return 0;
}
