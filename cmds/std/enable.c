// enable.c

#include <ansi.h>

inherit F_CLEAN_UP;

protected string displa_skill(object me,string skills);

mapping valid_types = ([
	"unarmed":	"ȭ��",
	"fork":		"ǹ��",  
	"dagger":	"�̱���",
	"hammer":	"����",
	"axe":		"����",
	"sword":	"����",
	"blade":	"����",
	"strike":	"�Ʒ�",
	"stick":	"����",
	"finger":	"ָ��",
	"staff":	"�ȷ�",
	"throwing":	"����",
	"iron-cloth":	"Ӳ��",
	"force":	"�ڹ�",
	"parry":	"�м�",
	"dodge":	"�Ṧ",
	"magic":	"����",
	"spells":	"����",
	"array":	"��",
	"whip":		"�޷�",
]);

int main(object me, string arg)
{
	mapping map;object ob;
	string *skill, ski, map_to,line;
	int i;

	seteuid(getuid());

	if( !arg )
	{
		ob=me;
		map = ob->query_skill_map();

		if( !mapp(map) || sizeof(map)==0 )
			line= MAG+"\n
��������������������������������������������������������������������������
��									��
��									��
��									��
��                ������û��ʹ���κ����⼼��	 	                ��
��									��
��									��
��									��
��									��
��������������������������������������������������������������������������
"NOR;

		else
			line =
sprintf("\n�������书���ࡿ����������������Ч���������书���ࡿ������������������Ч��
��ȭ��(unarmed):%s �޷�(   whip   ):%s�� 
��ǹ��( fork  ):%s �ڹ�(  force   ):%s�� 
������( hammer):%s Ӳ��(iron-cloth):%s��  
������(  axe  ):%s �м�(  parry   ):%s��  
������( sword ):%s �Ṧ(  dodge   ):%s��  
������( blade ):%s ����(  magic   ):%s��  
������( stick ):%s ����(  spells  ):%s��  
���ȷ�( staff ):%s ����(  stick   ):%s��
��������������������������������������������������������������������������
",
displa_skill(ob,"unarmed"),displa_skill(ob,"whip"),displa_skill(ob,"fork"),
displa_skill(ob,"force"),displa_skill(ob,"hammer"),displa_skill(ob,"iron-cloth"),
displa_skill(ob,"axe"),displa_skill(ob,"parry"),displa_skill(ob,"sword"),
displa_skill(ob,"dodge"),displa_skill(ob,"blade"),displa_skill(ob,"magic"),
displa_skill(ob,"stick"),displa_skill(ob,"spells"),displa_skill(ob,"staff"),
displa_skill(ob,"array"),displa_skill(ob,"dagger"),displa_skill(ob,"stick")
);

		write(line);

		return 1;
	}

	if( arg=="?" )
	{
		write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );

		for(i=0; i<sizeof(skill); i++)
		{
			printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
		}
		return 1;
        }

	if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("ָ���ʽ��enable [<��������> <��������>|none]\n");

	if( undefinedp(valid_types[ski]) )
		return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");

	if( map_to=="none" )
	{
		me->map_skill(ski);
		me->reset_action();
		if(me->is_fighting())
			me->start_busy(1);
		write("Ok.\n");
		return 1;
	}

	else if( map_to==ski )
	{
		write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
                return 1;
        }

	if( !me->query_skill(map_to, 1) )
		return notify_fail("�㲻�����ּ��ܡ�\n");

	if( !me->query_skill(ski, 1) )
		return notify_fail("������" + to_chinese(ski) + "����ûѧ�ᣬ������" + to_chinese(map_to) + "�ˡ�\n");

	if( !SKILL_D(map_to)->valid_enable(ski) )
		return notify_fail("������ܲ��ܵ���������;��\n");

	me->map_skill(ski, map_to);
	me->reset_action();
	write("Ok.\n");
        
        if( ski=="magic" ) {
                write("�������һ�ַ���ϵ�������������¶�����\n");
                me->set("atman", 0);
        } else if( ski=="force" ) {
                write("�������һ���ڹ��������������¶�����\n");
                me->set("force", 0);
        } else if( ski=="spells" ) {
                write("�������һ������ϵ��������������������\n");
                me->set("mana", 0);
        }

	if(me->is_fighting())
		me->start_busy(1);
        return 1;
}

protected string displa_skill(object me,string skills)
{
	mapping map;
	string *skill;
	int modify;

	map = me->query_skill_map();
	skill = keys(valid_types);

	if( undefinedp(valid_types[skills]) )
	{
		map_delete(map, skills);
			return sprintf("%|19s","�㻹����");
	}

	if( !me->query_skill(skills) )
		return sprintf("%|19s","�㻹����");

	modify = me->query_temp("apply/" + skills);

	if( !me->query_skill(skills, 1) )
		return sprintf("%|19s","�㻹����");

	return sprintf("%s",undefinedp(map[skills]) ? sprintf("%|19s","��"):
		sprintf("%|14s%5d",to_chinese(map[skills]),me->query_skill(skills)) );
}

int help(object me)
{
        write(@HELP
ָ���ʽ : enable [<��������> <��������> | none]
           enable ?
���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�� ? ���г�
������ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}
