// practice.c
// Modifide by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

/* ���ȼ����� 250 ������ 500 ʱ��ϰ�����Ӽ��ܵȼ���
 * ��ϰ����ߵȼ�����˵��츳��ͬ��С�в�𣬵���
 * �����ȼ����Ժ�ÿ��ϰһ��Ҳ��Ҫһ��Ǳ�ܡ�
 */
int main(object me, string arg)
{
	string skillname,sd;
	int skill, skill_basic;
	int amount;

	seteuid(getuid());
	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("�����û��ѧ�᡹����ܰɣ������ȥ��̱��ˡ�\n");
	if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

	notify_fail("�����ڲ�����ϰ����ܡ�\n");

	if(skill >= 250 && ((int)me->query("learned_points") >= (int)me->query("potential")) )
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ��޷�������������"+to_chinese(skillname)+"��\n");

	if(skill > 500)
		return notify_fail(sprintf("���Ѿ��޷�ͨ���Լ���ϰ��߶ԡ�%s��������ˡ�",
			to_chinese(skillname) ));

	if(me->query("sen") < 15)
		return notify_fail(sprintf("��Ŀǰ�ľ���̫��޷�����[%s]��\n",to_chinese(skillname)));

	me->start_busy(1);

	sd = (string)SKILL_D(skillname);

	if( sd->type()=="martial"
	&& skill * skill * skill/10 > me->query("combat_exp") )
		return notify_fail(sprintf("����ȱ��ʵս���飬���޷�����������[%s]��\n",
			to_chinese(skillname)));

	notify_fail(sprintf("��������ϰ��%s�������ǲ�û���κν�����\n",to_chinese(skillname)));

	if( sd->practice_skill(me) )
	{
		int pb = sd->practice_bonus();

		if(pb > -10)
			pb = -10;

		amount = (skill - 75) * (sd->black_white_ness())/100;
		if((amount < -25) && (skill < 75)) amount = -25;
		//amount += SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
		amount += (me->query_int()/2 + me->query("combat_exp")/(skill>=250 ?3000:2500))/5 + pb;
		if( amount < 1)
			amount = 1;
		if(skill>=250)
			me->add("learned_points", 1);
		me->improve_skill(skillname, amount,skill>=250 ? 0:1 );
		write(sprintf( HIY "��ԡ�%s�������ü�����һ����⡣\n" NOR,to_chinese(skillname)));
		me->receive_damage("sen",10,"tire");
		me->stop_busy();
		return 1;
	}

        me->stop_busy();
        return 0;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��practice <��������>

    ���ָ��������ϰĳ������ļ��ܣ�������ܱ���
�Ǿ��� enable ��רҵ���ܡ���ÿ��������ʱ�򣬱���
�����ʦ��ѧϰ������������ܵļ���
    �����������רҵ�������˺���ĸ�����ʱ�򣬲�
�п���ͨ����ϰ�������ܵĵȼ��������Ÿ�������
�Ĳ�ͬ��ϰ��һ���̶Ȼ�����ƿ�������ƿ���Ǻ���ͻ
�Ƶġ�

TEXT
	);
	return 1;
}
