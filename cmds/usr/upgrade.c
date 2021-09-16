// upgrade.c
// by Find.

// ÿ����һ���书��Ҫ�ķ�20�㾫��
#define COST_GIN	20
#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�����ô�ҵ���\n",
        "�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

int main(object me, string arg)
{
	string skill, teacher, mclass,*items = ({"str","cor","int","con","kar","per"});
        object ob, couple_ob;
        int master_skill, my_skill,sd,step_sd,need_sd,canlearn=0,i,have_qn,need_qn;
	mapping attr = (["str":0,"cor":0,"int":0,"con":0,"kar":0,"per":0]),marry;
	mapping cue  = (["str":"���������",
			 "cor":"��ʶ�����",
			 "int":"���������",
			 "con":"���ʸ�����",
			 "kar":"��Ե�����",
			 "per":"��òƯ����"]);

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("ָ���ʽ��upgrade <����> from <ĳ��>\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");

	if( !living(ob) )
		return notify_fail(sprintf("����Ȱ�%sŪ����˵��\n",ob->name()));

	if(userp(ob) && wizardp(ob) && !wizardp(me))
	{
                sys_log("learn",sprintf("(%s) want to learn \"%s\" from (%s).\n",
			me->query("id"),skill,ob->query("id")));
		return notify_fail("��������ʦѧϰ�书��\n");
	}

#ifdef WIZARD_FLAG
	if(ob->query_wiz_flag() && !wizardp(me))
		return notify_fail("��������û����"+ob->name()+"����ѧ���κζ�����\n");
#endif

        if( mapp(marry = me->query("marry")) )
		couple_ob = find_player(marry["id"]);

        if( !me->is_apprentice_of(ob))
	{
		if(couple_ob != ob)
		{
                        notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
			if( !(ob->recognize_apprentice(me)) )
				return 0;
		}
	}

        if( !master_skill = ob->query_skill(skill, 1) )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	notify_fail("�����书���޷�ѧϰ��\n");

	if(!(mclass = query_skill_class(skill)))
		return 0;

	if((mclass == "npc_skill") && userp(me))
		return 0; /* User can't learn 'NPC ONLY skill'. Find*/

	if( (mclass != "basic")
	&& (mclass != "public")
	&& (mclass != me->query("class")))
		return 0; // ����ѧϰ���ɵ��书. 

	if( function_exists("prevent_learn",ob) && !ob->prevent_learn(me, skill) )
                return 0;

        if( ob == couple_ob) // by Find.
        {
		// ����֮��ֻ��ѧϰ basic �书
		canlearn=1;
		if( mclass != "basic")
			return 0;
        }

        my_skill = me->query_skill(skill, 1);
        if( my_skill >= master_skill )
	{
		if(!canlearn)
			return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
		else
			return notify_fail("�������ĳ̶��Ѿ�������İ����ˡ�\n");
	}

        notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");

	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	attr["str"]=me->query("str");
	attr["cor"]=me->query("cor");
	attr["int"]=me->query("int");
	attr["con"]=me->query("con");
	attr["kar"]=me->query("kar");
	attr["per"]=me->query("per");

	if( (have_qn = me->query("potential") - me->query("learned_points")) <= 0 )
		return notify_fail(sprintf("���Ǳ���Ѿ����ӵ����ޣ��޷�����[%s]�ˡ�\n",to_chinese(skill)));

	if(me->query("gin") < COST_GIN)
		return notify_fail(sprintf("��Ŀǰ������״��̫��޷���������[%s]��\n",to_chinese(skill)));

	if( (string)SKILL_D(skill)->type()=="martial"
	&& my_skill * my_skill * my_skill/10 > me->query("combat_exp") )
		return notify_fail(sprintf("����ȱ��ʵս���飬���޷�����������[%s]��\n", to_chinese(skill)));

	if(userp(ob))
	{
		if(ob->query("sen") < 10)
			return notify_fail(sprintf("%s���ڹ������ۣ��޷����㴫��[%s]��\n",
				ob->name(),to_chinese(skill)));
		else
			ob->receive_damage("sen",10,"tire");
	}

	sd = me->query_sd(skill);
	need_sd = (my_skill + 1) * (my_skill + 1) + 1;
	printf("����%s�ֽ��йء�%s�������ʡ�\n", ob->name(),to_chinese(skill));
	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");
	if(canlearn!=1)
	{
		if(userp(ob))
			tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
				me->name(), to_chinese(skill)));
	}
        else
		tell_object(ob, sprintf("%s����������йء�%s�������⡣\n",
               		me->name(), to_chinese(skill)));

	if( sd >= need_sd )
		me->improve_skill(skill,1);

	else
	{
		step_sd = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
		if((step_sd < -50) && (my_skill < 75))
			step_sd = -50;
		step_sd  += (me->query_int()/2 + me->query("combat_exp")/1500)/5 + SKILL_D(skill)->learn_bonus();
		if( step_sd < 1)
			step_sd = 1;

		need_qn = (need_sd - sd)/step_sd;
		if(need_qn < 1)
			need_qn = 1;
		if(have_qn < need_qn)
			return notify_fail(sprintf("����Ŀǰ[%s]�������ȣ�����Ҫ %d ��Ǳ���������ȼ���\n",
				to_chinese(skill),need_qn));

		me->add("potential",-need_qn);
		me->improve_skill(skill,(need_sd - sd));
	}

	me->receive_damage("gin",COST_GIN,"tire");
	for(i=0;i<sizeof(items);i++)
	{
		if(attr[items[i]] > me->query(items[i]))
		{
			write(sprintf(HIC+"�������%s��ϰ�гɣ����%s��\n"+NOR,
				to_chinese(skill),cue[items[i]]));
			break;
		}
	}

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : upgrade <����> from <ĳ��>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ���������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱��һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲô��������ģ����Ǿ���ʵ���ϵ�Ӧ����
�������⣬��Щ�������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ�ģ������Ǹ�����Ϊ������
�ܻ����Ļ������ܣ�����Ҫ���ɡ��������⡪������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��
������ǽ����ַ�������Ĺ����á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ��
�⣬��ʾ��(��)�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ��
������������̣�����ý�����
(PS. Ǳ�ܻ�������������Ķ��壬����ֻ������֮һ )

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�

�������֪�����ܴӶԷ�ѧ��ʲô���ܣ�����Է������ʦ���������� skills ָ��
ֱ�Ӳ鿴������������ʦ������ôͨ��������������ʾ����ֻ���Լ���취��

�������ָ�� : practice��study
HELP
        );
        return 1;
}
