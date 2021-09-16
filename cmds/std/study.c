// study.c
// Modified by Find.

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,env;
	mapping skill;
	int cost,my_skill;
	string cls;

	if(!objectp(env = environment(me)))
		return 0;

	if(env->query_dark_level())
		return notify_fail("��������û��һ�����⣬ʲôҲ�����ˡ�\n");

	if( me->is_fighting() )
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if(!arg || !objectp(ob = present(arg, me)) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( !mapp(skill = ob->query("skill")) )
		return notify_fail("���޷�����������ѧ���κζ�����\n");

#ifdef WIZARD_FLAG /* by Find.*/
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("���޷��ӡ���ʦ��Ʒ����ѧ���κζ�����\n");
#endif

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧѧ����ʶ��(literate)�ɡ�\n");


	message_vision(sprintf("$N��ר�ĵ��ж�%s��\n",ob->name()),me);

	notify_fail("Ҳ��ȱ��ĳЩ���ϣ���������֪ʶһ��Ҳ�޷�����\n");

	if(!(cls = query_skill_class(skill["name"])))
		return 0;
	if( (cls == "npc_skill") && userp(me))
		return 0; /* User can't learn 'npc only skill'. Find */

	if( (cls != "basic")
	&& (cls != "public")
	&& (cls != me->query("class")))
		return 0; // ����ѧϰ���ɵ��书.

        if(skill["party"] && skill["party"]!=me->query("class"))
                 return notify_fail("Ҳ��ȱ��ĳЩ���ϣ���������֪ʶһ��Ҳ�޷�����\n");

	if( (int)me->query("combat_exp") < skill["exp_required"] )
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");

	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
	if( !SKILL_D(skill["name"]) || !SKILL_D(skill["name"])->valid_learn(me) )
		return 0;

	if(!undefinedp(skill["min_skill"])
	&& ((me->query_skill(skill["name"],1) < skill["min_skill"])) )
		return notify_fail(sprintf("���%s����̫����޷�������������ݡ�\n",
			to_chinese(skill["name"])));

	cost = skill["sen_cost"] + skill["sen_cost"] 
		* (skill["difficulty"] - (int)me->query_int())/20;
	if (cost<1) cost=1;

	if( (int)me->query("sen") < cost )
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");

	if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");

	me->receive_damage("sen", cost);

	my_skill = me->query_skill(skill["name"], 1);

	if( (string)SKILL_D(skill["name"])->type()=="martial"
	&& my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") )
		printf("Ҳ����ȱ��ʵս���飬���%s������˵�Ķ��������޷���ᡣ\n", ob->name());

	else
	{
		if( !me->query_skill(skill["name"], 1) )
			me->set_skill(skill["name"], 0);
		me->improve_skill(skill["name"], (int)me->query_skill("literate", 1)/3+1);
		write("���ж��й�" + to_chinese(skill["name"]) + "�ļ��ɣ��ƺ��е��ĵá�\n");
	}
	return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study <��Ʒ����>

���ָ��ʹ����Դ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����
��Ȼ�����ѧ����Խ����������Խ�졣

see also : learn
HELP
   );
   return 1;
}
