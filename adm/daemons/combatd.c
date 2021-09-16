// combatd.c
// by Find.

#pragma optimize

#include <armor.h>
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <mangle.h>

inherit F_DBASE;
void winner_announce(object ob1, object ob2);

// hand_flag 0 ��ʾ���ֳ���, 1 ��ʾ���ֳ���.
static int hand_flag = 0;

/*��Щ��λһ��Ϊ�����ϼӱ����ĵط�������Щ��λ
 *�����ɹ��Ŀ����Լ�С��һ�����ֱ��������ܵ���
 *��Ҳ��Խϴ�
 */
string *danger_limbs = ({
"ͷ��",	"����",	"�ؿ�",	"����","С��",
});

mapping armor_vs_limb = ([
"ͷ��" : ({ TYPE_HEAD }),
"����" : ({ TYPE_NECK }),
"�ؿ�" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"����" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"���" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"�Ҽ�" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"���" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"�ұ�" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"����" : ({ TYPE_HANDS }),
"����" : ({ TYPE_HANDS }),
"����" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT,TYPE_WAIST }),
"С��" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT,TYPE_WAIST }),
"����" : ({ TYPE_ARMOR }),
"����" : ({ TYPE_ARMOR }),
"���" : ({ TYPE_BOOTS }),
"�ҽ�" : ({ TYPE_BOOTS }),
]);

//added by find. ÿ�� PK �������ιٸ���ʼ�Դ��˽���Χ��.
//Ϊ���� quit �ӱ�Χ��,�� condition ��ʽ.

varargs protected void player_was_die(object user,mixed ob, int ry_falg);

protected int valid_killer(object victim, object killer)
{
	object *first_kill;

	if(!killer || !userp(killer) || !victim || !userp(victim))
		return 0;

	victim->delete_temp("players_kill_me");
	if(arrayp(first_kill = killer->query_temp("players_kill_me"))
	&& (member_array(victim, first_kill) != -1) )
	{
		first_kill -= ({ victim });
		first_kill -= ({ 0 });
		killer->set_temp("players_kill_me", first_kill);
		return 0;
	}

	return 1;
}

protected void check_pker(object victim, object killer)
{
	if(!killer || !userp(killer) || !victim || !userp(victim))
		return;

        if(!killer->query("pk_time"))
        {
                killer->set("pk_time",time());
                killer->set("crazy_pk",0);
                return;
        }

        if( (time() -  killer->query("pk_time")) <= 24*60*60 )
                killer->add("crazy_pk",1);
        else
        {
                killer->set("pk_time",time());
                killer->set("crazy_pk",1);
        }

        if( (int)killer->query("crazy_pk") >= 2 )
        {
                killer->set("is_pker",1);
                killer->apply_condition("pker_kill",600);
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s���������ˣ��ٸ���ʼ��%s����Χ�ˡ�", killer->name(1), 
                        gender_pronoun(killer->query("gender"))));
        }
}
//end.

string  *head_damage_me_msg = ({
	"�����ͷ��һ�㷢�Ρ�\n",
	HIB "�����һ����ѣ���������һ�¡�\n" NOR,
	BLU "��ֻ����ð���ǣ�����Ʈ��\n" NOR,
});

string *body_damage_me_msg = ({
	"��ֻ��$l������ʹ�����������ܵ�һ���񵴡�\n",
	HIB "��ֻ��$l���ۣ���������һ���Ҵܡ�\n" NOR,
	BLU "��ֻ����$l����ʹ����������������һ����й��\n" NOR,
});

string *guard_msg = ({
        CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
        CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
        CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
        CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
        CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
        HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
        HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
        HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
        HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
        HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
        HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
       CYN "\n$N������Ц������˵���������ˣ�\n\n" NOR,
       CYN "\n$N˫��һ����Ц��˵����֪���ҵ������˰ɣ�\n\n" NOR,
       CYN "\n$Nʤ�����У����Ծ�����ߣ�̾�������ǰν��Ĺ���ãȻ��\n\n" NOR,
       CYN "\n$n����ȷʵ�˵ã�ʮ�������һ��ǰ����̣� \n\n" NOR,
       CYN "\n$n������˼�����˵�����ⳡ�����������ˣ��»ؿ�����ô��ʰ�㣡\n\n" NOR,
       CYN "\n$n���һ�ݣ��޺޵�˵�������ӱ���ʮ�겻��\n\n" NOR,

});

protected void create()
{
        seteuid(getuid());
        set("name", "ս������");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;
        if( damage == 0 ) return "���û������κ��˺���\n";
        switch( type ) {
        case "����":
        case "����":
                if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
                else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
                else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
                else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
                else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
       case "����":
	        if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
 	        else if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
	        else if( damage < 40 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
	        else if( damage < 80 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
	        else if( damage < 120 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
	        else if( damage < 160 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
	        else if( damage < 240 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
	        else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
	        break;

        case "����":
                if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
                else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
                else if( damage < 40 ) return "������ۡ���һ��������$n$l����\n";
                else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
                else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ�������Ѫ������\n";
                else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        
	case "����":
                if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
                else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                else if( damage < 120 ) return "������项��һ����$n����������\n";
                else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
                else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                break;
        
	case "ץ��":
                if( damage < 10 ) return "���ֻ�������ץ������ץ����΢���˵㡣\n";
                else if( damage < 20 ) return "�����$p��$lץ������Ѫ�ۡ�\n";
                else if( damage < 40 ) return "���һץ���У�$n��$l��ץ����Ѫ�ɽ���\n";
                else if( damage < 80 ) return "������͡���һ����$l��ץ����ɼ��ǣ���\n";
                else if( damage < 120 ) return "���һץ���У�$n��$l��ץ��Ѫ���ɣ�����\n";
                else if( damage < 160 ) return "�����һ�¡��͡���һ��ץ��$n���κü��£���һ��ˤ����\n";
                else if( damage < 240 ) return "���$n����һ����$l��ץ�ý�Ϲ��ۣ���\n";
                else return "���ֻ����$nһ���Һ���$l��ץ�����Ѫ��������Ѫ�������أ���\n";
                break;
        
	case "����":
                if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                else if( damage < 20 ) return "�����$n���������һ�����ˡ�\n";
                else if( damage < 40 ) return "���$nһ֧�ֱ�Ťס���ֱ۵�ʱ���һ��Ť�ˣ�\n";
                else if( damage < 80 ) return "���$n���ű���ס����Ϣɢ�ң����һ���������ˣ�\n";
                else if( damage < 120 ) return "�����ž����һ����$n��˫�۲�㱻�۶ϣ�\n";
                else if( damage < 160 ) return "�����һ�¡�ž��һ����$n�ֱ��۶ϣ�ʹ����������һ�£�\n";
                else if( damage < 240 ) return "���$nȫ������ɢ�ܣ�ʹ�ļ������˹�ȥ��\n";
                else return "���ֻ����$n�ҽ�һ����������ϣ���\n";
                break;
        
	case "������":
                if( damage < 5 ) return "$N�ܵ�$n$z�ķ����ƺ�һ����\n";
                else if( damage < 10 ) return "$N��$n��$z�����Ѫ���ڣ���ʧɫ��\n";
                else if( damage < 20 ) return "$N��$n��$z���վ�����ȣ�ҡҡ�λΡ�\n";
                else if( damage < 40 ) return "$N��$n��$z���𣬡��١���һ������������\n";
                else if( damage < 80 ) return "$N��$n��$z����������������ð����顣\n";
                else if( damage < 120 ) return "$N��$n��$z������һ���ؿ������ܵ�һ���ػ�����������������\n";
                else if( damage < 160 ) return "$N��$n��$zһ����ǰһ�ڣ��������ɳ�������\n";
                else return "$N��$n��$zһ����ǰһ�ڣ�������Ѫ������������ߵķ�������ȥ����\n";
                break;
        default:
                if( !type ) type = "�˺�";
                if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
                else if( damage < 20 ) str = "��������΢��";
                else if( damage < 30 ) str = "������һ��";
                else if( damage < 50 ) str = "������һ������";
                else if( damage < 80 ) str = "��������Ϊ���ص�";
                else if( damage < 120 ) str = "�������൱���ص�";
                else if( damage < 170 ) str = "������ʮ�����ص�";
                else if( damage < 230 ) str = "�����ɼ������ص�";
                else str =  "�����ɷǳ����µ�����";
                return str + type + "��\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
        if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
        if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
        if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
        if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
        if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
        if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object ob, int effective)
{
        if( effective ) 
                message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("eff_kee") * 100 / (int)ob->query("max_kee") ) 
			+ " )\n", ob);
        else
                message_vision( "( $N" + status_msg(
                        (int)ob->query("kee") * 100 / (int)ob->query("max_kee") ) 
                        + " )\n", ob);
}

varargs int give_exp(int exp)
{
	if(exp <= 20000) return 4;
	if(exp <= 40000) return 3;
	if(exp <= 80000) return 4;
	if(exp <= 160000) return 5;
	if(exp <= 320000) return 6;
	if(exp <= 640000) return 7;
/*
	if(exp <= 1280000) return 8;
	if(exp <= 2560000) return 9;
	if(exp <= 5120000) return 10;
*/
	return 8;
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
        int status, level, power, maxenc, enc, rtn;

	if( (int)ob->query_encumbrance() < 0 )
		return 0;  // ����С����ʱ power ��Զ������(by find.)

	if(userp(ob) && ob->is_ghost())
		return 0; // ���Ĺ�����Ϊ 0.

	maxenc = (int)ob->query_max_encumbrance();
	enc = (maxenc - (int)ob->query_encumbrance()) * 100 / maxenc;

        if(!living(ob)) return 0;

        level = ob->query_skill(skill);

        switch(usage) 
	{
                case SKILL_USAGE_ATTACK:
                        level += ob->query_temp("apply/attack");
                        break;
                case SKILL_USAGE_DEFENSE:
                        level += ob->query_temp("apply/defense");
                        break;
		case SKILL_USAGE_ABSORB:
			level += ob->query_temp("apply/iron-cloth");
			if(!level)
				return 0;
			break;
        }

	if( !level )
		return (int)ob->query("combat_exp") / 2 /
		((userp(ob) && (!ob->query("food") || !ob->query("water")))?
		2:1);
		/*��ʳ���ˮ����һ��Ϊ 0���������롣*/

        if( (status = ob->query("max_sen")) > 0 )
	{
		if (level>100)
                        power=level*level/3/status*(int)ob->query("sen")*level;
		else
                        power=level*level*level/3*(int)ob->query("sen")/status;
        }

	else
	{
                if (level>100)
                        power=level*level/3*level;
		else
                        power=level*level*level/3;
        }

	if( (usage == SKILL_USAGE_DEFENSE) && ob->in_array() )
	{
		int n;
	
		if( (n =  ob->query_array_level()/100) )
		{
			if(n < 10)
				power += power*n/100;
			else
				power += power/100*n;
		}
	}

	rtn = ( (power + ob->query("combat_exp")) /100 *enc)/
		((userp(ob) && (!ob->query("food") || !ob->query("water")))?
		2:1);
		/*��ʳ���ˮ����һ��Ϊ 0���������롣*/

	if(ob->query_xuruo())
		rtn /= 2;
	if( (skill == "unarmed") && (ob->query_limb_wound("����") || ob->query_limb_wound("����")) )
		rtn /= 2;
	return rtn;
}

nomask int math_ap(object me) /* ����ap */
{
	object weapon,second_weapon;
	int ap,aap,skill/*,second_skill*/;

	weapon = me->query_temp("weapon"); /* ���ֱ��� */
	second_weapon = me->query_temp("secondary_weapon"); /* ���ֱ��� */

	if(objectp(weapon))
	{
		ap = skill_power(me, weapon->query("skill_type"), SKILL_USAGE_ATTACK);
		/* ���������ֱ������������ֱ���,ֻҪ�������־������������㹥����. */

		if(second_weapon) /* ���˫�ֶ����˱��� */
		{
			if(weapon->query("skill_type") == second_weapon->query("skill_type"))
			/* ��������õı�����ͬ�����,�жϴ��˴����书�ĵȼ� */
			{
				skill = me->query_skill(weapon->query("skill_type"),1);
				if( skill >= 200)
					ap += ap/8;
				else if(skill > 100)
					ap += ap/10;
			}

			else /* ��ͬ���� */
			{
			aap = skill_power(me, second_weapon->query("skill_type"),
				SKILL_USAGE_ATTACK);
			ap = ap/100*80 + aap/100*35;
			/* ���ֱ����ļ�������������ֱ����ļ���̫�࣬
			   ���ڲ��ܺܺõ���ϣ�����������Ҫ���͡�*/
			}
		}
	}

	else
	{
		if(objectp(second_weapon)) /* ���ֻ�������ñ��� */
			aap = skill_power(me, second_weapon->query("skill_type"),
				SKILL_USAGE_ATTACK);

		ap = skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
		if(aap)
			ap = ap/100*80 + aap/100*35;
			/* ���ֱ����ļ�������������ֿ��ֵļ���̫�࣬
			   ���ڲ��ܺܺõ���ϣ�����������Ҫ���͡�*/
	}

	if(me->is_busy()) ap /= 3;
	if(ap < 1) ap = 1;

	return ap;
}

nomask int math_dp(object me, object weapon) /* ����dp */
{
	int dp,tp;

	dp = skill_power(me, "dodge", SKILL_USAGE_DEFENSE);

	if(objectp(weapon) && (weapon->query("skill_type") == "throwing"))
	{
                tp = skill_power(me, "perception", SKILL_USAGE_DEFENSE);
		dp /= 2;
		if(tp > dp)
			dp = tp;
	}

	dp -= dp*(me->query_cor())/1000;
	if(me->is_busy())
		dp /= 3;
	if(dp < 1)
		dp = 1;
	return dp;
}

int math_pp(object me) /* ����pp */
{
	int pp;

	pp = skill_power(me, "parry", SKILL_USAGE_DEFENSE);

	// �����Ƿ����ڵ�ʶ�߶�����?
	pp -= pp*(me->query_cor())/1000;
	if(me->is_busy())
		pp /= 3;
	if(pp < 1)
		pp = 1;

	return pp;
}

protected mapping decide_action(object me,
	int flag /* flag = 1 ָ������ */
	) /* ѡ����˵ĳ���. */
{
	mapping act,l_act;

        act = me->query("actions"); /* ���˵����� action */
        if(!mapp(act))
	{
                me->reset_action();
                act = me->query("actions");
                if(!mapp(act)) 
		{
                        CHANNEL_D->do_channel( this_object(), "sys",
	                                sprintf("%s(%s): bad action = %O",
                                        me->name(1), me->query("id"), 
					me->query("actions", 1)));
                        return 0;
                }
	}

	l_act = me->query("second_actions"); /* ���˵����� action */
	if(!mapp(l_act) || !sizeof(l_act))
	{
		hand_flag = 0;
		return act;
	}

	if(flag) // ָ������
	{
		hand_flag = 1;
		return l_act;
	}

	/* ʲô���ؾ������������ֹ������������ֹ���? Ŀǰû��,�������������.*/
	if(random(100) < 55) /* ���ֵĿ����Դ�һЩ.*/
	{
		hand_flag = 0;
		return act;
	}
	else
	{
		hand_flag = 1;
		return l_act;
	}
}

/***********************************************
 * �Է���ʽ�����������мܻ��Ƕ���.
 * ��Ӱ�����������:
 * 1. �Լ��Ƿ��ñ���? �ñ����мܵĿ����Դ�.
 * 2. �Է��Ƿ��ñ���? �Է��ñ��������Ŀ����Դ�.
 * 3. dp �� pp �Ĵ�С,
 *	dp > pp ���������Դ�.
 *	pp > dp �мܵĿ����Դ�.
 * 4. �Լ�ͬʱ�е�һ�ڶ������мܿ����Դ�.
 ***********************************************/
protected string
decide_attact_result(object me, object victim,int ap,int dp,int pp,int flag)
{
	int ratio = 50;	// + �мܵĿ����Դ� - �����Ŀ����Դ�.
	/*
	string *heavy_weapon = ({"axe","hammer","whip"});
	string *sharp_weapon = ({"blade","sword"});
	*/
	object weapon_me,weapon_v;
	string decide;

	if( !me || !victim )
		return ERROR_RESULT;

	if(userp(victim) && victim->in_wizard_guard())
		return "guarded";

	if(!flag) // ���˵���ֻ���м�
	{
		if(hand_flag)
			weapon_me = me->query_temp("secondary_weapon");
		else
			weapon_me = me->query_temp("wepon");
	
		weapon_v  = victim->query_temp("weapon");
		if(!weapon_v)
			weapon_v = victim->query_temp("secondary_weapon");
	
		// �ж϶��ڴ����Ƕ��������м�.
		if(weapon_me)  // �������б���?
		{
			ratio -= 5;
			if(weapon_me->query("falg") & EDGED) // �����ı���
				ratio -= 5;
		}
	
		if(weapon_v)
		{
			ratio += 5;
			if(weapon_v->query("skill_type") == "throwing") // ����,�Զ���Ϊ��
				ratio -= 10;
			if(weapon_v->query("flag") & TWO_HANDED)
				ratio += 5;
			if(victim->query_temp("weapon")
			&& victim->query_temp("secondary_weapon") ) // ˫�ֶ��б���,�мܿ����Դ�.
				ratio += 8; 
		}
	
		if( pp > dp ) // �мܼ��ܸ��ڶ�������
			ratio += 10;
		else
			ratio -= 10;
	
		if(random(100) <= ratio)
			decide = "parry";
		else
			decide = "dodge";
	}
	else
		decide = "parry";

	if(decide == "parry")
	{
		if(random(ap + pp) < pp)
			return "parryd"; // �м�
	}

	else
	{
		if(random(ap + dp) < dp)
			return "dodged"; // ����
	}

	return "attackd"; // ����
}

protected void get_dodge_reward(object me,object victim)
{
	int exp_me,exp_v,gain,valve;

	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// ����һ�����ڻ���״̬��û���κν�����
	if(userp(me) && userp(victim)) // user �Դ�
		return;
	if(me->query("no_exp_gain"))	// ������ľ���� npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if( exp_v >= 2000 &&
	(exp_me <= exp_v/2
	// �Է����Լ���̫��㿪���������ײ
	// ʲôҲ�ò�����
	|| exp_me >= exp_v*2))
		return;

	// �������ķ�ֵ��
	valve = 12 + victim->query("age") - 16;
	if(valve < 12)
		valve = 12;
	if(valve > 32 )
		valve = 32;

	// gain Ӧ�ú͹����ߵľ�����أ�
	// �����ߵľ���Խ�ߣ������ߵ���
	// �˶���õ�ս������ҲӦ��Խ��
	// ��֮Խ�͡�
	gain = random(give_exp(exp_me));
	if(gain < 1)
		gain = 1;

	// ս�����ܻ�ö����ջ��һ���˵�
	// ����������ϢϢ��صģ������ֵ
	// �ļ����������������أ��Ӷ���
	// �����书�����Ժ��������������
	// ��Խ��ԽСֱ�����Ժ��Բ��ǵ���
	// �������Ե�Ӱ��������ÿһ���׶�
	// ��Ӧ�����ƽ��ġ���Ϊ���뽭
	// ����˵���Եͣ�����ʱ����Ҫ����
	// ���书Ҳ��ǳ�ԣ��Ժ��������ӣ�
	// ����Ҫ������书ҲԽ��Խ���
	// �������仹�������ֳ�������ϰ��
	// Խ��ѧ��Խ�죬��������ʮ���ٿ�
	// ʼ����������ɵ���Ȼ���ɡ�
	// ����ȡ���� query_int()��������
	// װ���Ŀ��������Եı�������ߵ�
	// ���Բ���Ҳ�������ڣ����ֳ��˱�
	// ������ã��Ӷ�����������Ϸ��
	// ���в���̽���Ķ���������������
	// �����õ�ƽ���ԣ�������ڸ�����
	// �ε���Ҷ������ֳ�������ļ�
	// ֵ�������ֵ�޶������ֵ������
	// �������ϰ�ʮû�������������
	if(random(victim->query_int()) >= valve)
	{
		victim->add("combat_exp",gain);
		victim->improve_skill("dodge", 1);
		if(random(100) < 50)
			me->add("potential",1);
	}

	// �������ߵľ�����ڶ����ߵľ���ʱ��
	// �������л�����һ����书����������
	// �ٴ��������ԡ�
	//if((exp_me >= exp_v) && (random(victim->query_int()) >= valve))
	//	victim->add("potential",1);
}

protected void get_parry_reward(object me,object victim)
{
	int exp_me,exp_v,gain,valve;
	
	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// ����һ�����ڻ���״̬��û���κν�����
	if(userp(me) && userp(victim)) // user �Դ�
		return;
	if(me->query("no_exp_gain"))	// ������ľ���� npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if( exp_v >= 2000 &&
	(exp_me <= exp_v/2
	|| exp_me >= exp_v*2))
		return;

	// �������ķ�ֵ��
	valve = 12 + victim->query("age") - 16;
	if(valve < 12)
		valve = 12;
	if(valve > 32 )
		valve = 32;

	gain = random(give_exp(exp_me));
	if(gain < 1)
		gain = 1;
	if(random(victim->query_int()) >= valve)
	{
		victim->add("combat_exp",gain);
		victim->improve_skill("parry", 1);
		if(random(100) < 50)
			me->add("potential",1);
	}

	// ֻ���ڶԷ���������Լ���ʱ��
	//if((exp_me > exp_v) && (random(victim->query_int()) >= valve))
	//	victim->add("potential",1);
}

protected void get_attack_reward(object me,object victim,string attack_skill)
{
	int exp_me,exp_v,gain,valve;
	
	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// ����һ�����ڻ���״̬��û���κν�����
	if(userp(me) && userp(victim)) // user �Դ�
		return;
	if(victim->query("no_exp_gain")) // ������ľ���� npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if(exp_me != 0 && exp_v <= exp_me/2)
/*
	|| exp_v >= exp_me*2)
*/
		return;

	// �������ķ�ֵ��
	valve = 12 + victim->query("age") - 16;
	if(valve < 12)
		valve = 12;
	if(valve > 32 )
		valve = 32;

	// �˴�gain Ӧ�úͱ�����ߵľ�����أ�
	// ������ߵľ���Խ�ߣ����д��˶����
	// ��ս������ҲӦ��Խ�ߣ���֮Խ�͡�
	gain = random(give_exp(exp_v));
	if(gain < 1)
		gain = 1;
	if(random(victim->query_int()) >= valve)
	{
		me->add("combat_exp",gain);
		// �� 80% �����Ի��Ǳ�ܡ�
		//if(random(100) < 80)
		//	me->add("potential",1);
	}
	else
		me->add("combat_exp",1);
	// �˴��书������������
	me->improve_skill(attack_skill, 1);

	// �� 80% �����Ի��Ǳ�ܡ�
	if(random(100) < 80)
		me->add("potential",1);
}

protected int count_armor_protect(object me,object armor,int factor,object weapon,int w_damage)
{
	int ret,fth,mangle,dd;
	string skill;

	// ������͸����������͸��׶֮��İ���
	if(objectp(weapon) && weapon->through_armor())
		return 0;

	// �����𻵳̶�
	mangle = armor->query("armor_mangle");
	if(mangle >= A_MAX_MANGLE)
		return 0;
	ret = armor->query("armor_prop/armor");

	// ������Ļ��ߣ���������ȡ�
	if(armor->cant_be_damage())
		return 1;

	if(mangle)
		ret = ret*(((A_MAX_MANGLE-mangle)*100)/A_MAX_MANGLE)/100;
	if(ret <= 0)
		return 0;

	// �ڹ��Ƿ��д�͸���׵�����
	// ����ﴫ������ɽ��ţ֮��
	// ͽ�ִ�������������
	if(!weapon)	// ͽ��
	{
		if(factor > 0 && (skill = SKILL_D(me->query_skill_mapped("force"))))
		{
			fth = skill->query_through_armor(me,factor);
			if(fth >= ret)	// ��͸�����ڷ�����
				ret = 0;
			else
				ret -= fth;
		}
		armor->set("armor_mangle",++mangle>A_MAX_MANGLE?A_MAX_MANGLE:mangle);
		return ret;
	}

	// �б������������ã���Ҫ����
	if(w_damage <= 0)
		return ret;	// ����û��ɱ�����������𻵻���

	// �����Ի��׵��˺�
	dd = (WEAPON_D->query_rigidity(weapon) - WEAPON_D->query_rigidity(armor))/10;
	if(dd < 1)
		dd = 1;

	armor->set("armor_mangle",(dd + mangle)>A_MAX_MANGLE?A_MAX_MANGLE:(dd + mangle));
	return ret;
}

// ������˵����Ⱥͱ���������ܵ��˺��̶�Ӧ������˵ĵ�ʱ����״̬�йء�
nomask varargs int
do_attack(object me,		/* ������*/
	  object victim,	/* ������*/
	  int attack_type,	/* ��������*/
	  int flag		/* ָ�����ֱ�� */
	)
{
	int ap, dp, pp, absp,i,n,pers,mangle;
	int damage, wound,factor,force,armor = 0,w_damage;
	int exp = 0;
	int wounded = 0,mute_flag = 1,array_flag;
        mapping action,fang_ju,w_action;
	mixed foo;
	string *limbs, limb, result, res,*armor_types,*verbs;
        string attack_skill, defense_skill, force_skill, martial_skill; 
	object weapon,second_weapon,weapon_v;

#ifdef WIZARD_FLAG	/* ��ʦ����Ҳ��ܷ���ս��. */
	if( userp(me)
	&& userp(victim)
	&& wizardp(me) != wizardp(victim))
		return 0;

	/* Player can not fight with wiz_ob npcs */
	if(me->query_wiz_flag() && userp(victim) && !wizardp(victim))
		return 0;
	if(victim->query_wiz_flag() && userp(me) && !wizardp(me))
		return 0;
#endif

	// ���˫��û�д���ս��״̬,���Է����ع��Ժ�����
	// surrender,��ʱ����ս��״̬,�Է����ṥ���Լ�,
	// ���Ƿ������ع�����ֹͣ,��Ȼ����Է�����.
	// ���ж�ֻΪ��������Ͷ��ȡ�ɵ����.
	// ��Ҳ�����һЩ����,���� entrap ֮��������״̬��
	// ͻȻ����ֱ�ӵ��� attack ���������,���������Ҫ
	// ���� me->fight_ob(ob) ʹ˫������ս��״̬�ٷ���,
	// ���б�Ҫ�ڷ��к��� me->remove_enemy(ob) ���ս��״̬.
	if(!me->is_fighting(victim) && !victim->is_fighting(me))
		return 0;

	weapon = me->query_temp("weapon");
	second_weapon = me->query_temp("secondary_weapon");

	// �ж� attacker �� action.
	action = decide_action(me,flag);
	if(!action) return 0;

	if(hand_flag)	/* ����'��ǰ����' weapon��*/
		weapon = second_weapon;

	if( !me->query("env/mute")
	&& (!victim->query("env/mute")
	|| (userp(me)
	&& userp(victim))) )
		mute_flag = 0;

	if(!mute_flag)
        	result = sprintf("\n%s��\n",action["action"]);

	if(objectp(weapon))
		attack_skill = weapon->query("skill_type");
	else
		attack_skill = "unarmed";

	// �жϹ�����λ

	/* �����ÿ���ʹһЩ�书ѡ��ʹ�ô��书���˵Ĺ�����λ��
	 * ���Բ���������˵���ר������·��Ч����
	 * �������Ӳ���ϵͳ�������������ڻ���Խ��Խ�졣
	 */
	if(martial_skill = me->query_skill_mapped(attack_skill))
		limb = SKILL_D(martial_skill)->query_attack_limb(me,victim);

	if(!limb)
	{
		limbs = victim->query("limbs");
		if(!limbs || !arrayp(limbs))
		{
			message_vision("COMBAT_D: $N������λ����\n",victim);
			return 0;
		}
		limb = limbs[random(sizeof(limbs))];
	}

	if(victim->in_array()
	&& victim->query_array_status()
	&& (random(100) < (victim->query_array_level()/100 + 40)) )
	{
		mapping vdb = victim->query_entire_dbase();
		object ob;

		if( ((vdb["kee"] < vdb["max_kee"]*2/5)
		|| (vdb["sen"] < vdb["max_sen"]*2/5))  // �����ˣ�����ס��
		&& objectp(ob = victim->query_array_obstructor()) )
		{
			if(!mute_flag)
			{
				result = replace_string( result, "$l", limb );
			        if( objectp(weapon) )
			                result = replace_string( result, "$w", weapon->name() );
			        else 
					if( stringp(action["weapon"]) )
			                	result = replace_string( result, "$w", action["weapon"] );
			       		else 
						if( attack_skill == "finger" ) 
					              result = replace_string( result, "$w", "��ָ" );

				message_vision(result, me, victim);
				message_vision(HIC BWHT"$N�����Ʋ���������$n����ǰ��\n"NOR,ob,victim);
				result = "";
			}

			victim = ob;
			array_flag = 1;
			attack_type = TYPE_QUICK;
		}
	}

	// ���� ap��dp��pp.
        ap = math_ap(me);

	if(!array_flag)
	{
	        dp = math_dp(victim,weapon);
	        if(action["dodge"])
			dp += action["dodge"] * dp / 1000;
	}

	pp = math_pp(victim);
        if(action["parry"])
		pp += action["parry"] * pp / 1000;

	if(member_array(limb,danger_limbs) != -1) /* ��Σ�ղ�λ�������� */
	{
		ap -= ap/10;	/* ���еĿ����Լ�С10% */
		if(ap <1)
			ap = 1;
	}

	// ����ս�������
	res = decide_attact_result(me, victim, ap, dp, pp, array_flag);

	switch(res)
	{
	case "guarded":
		if(!result)
			result = HIC"$n���ӳ��һ����ɫ�Ĺ⻷����$N����ʽ����������\n"NOR;
		else
			result += HIC"$n���ӳ��һ����ɫ�Ĺ⻷����$N����ʽ����������\n"NOR;
		break;

	case "dodged":	// ����
		defense_skill = victim->query_skill_mapped("dodge");
		if(!defense_skill)
			defense_skill = "dodge";
		if(!mute_flag)
			result += SKILL_D(defense_skill)->query_dodge_msg();
		break;

        case "parryd": // �м�
		defense_skill = victim->query_skill_mapped("parry");
		if(defense_skill)  /* ����������ʱ�� parry ��ʾ��Ϣ��*/
		{
			if( !objectp(weapon_v = victim->query_temp("weapon")) )
				weapon_v = victim->query_temp("secondary_weapon");
			if( objectp(weapon_v) )
			{
				if( !SKILL_D(defense_skill)->valid_enable(weapon_v->query("skill_type")) )
					defense_skill = 0;
			}
		}

		if(!defense_skill || !weapon_v)
			defense_skill = "parry";
		if(!mute_flag)
			result += SKILL_D(defense_skill)->query_parry_msg(weapon,weapon_v);

		break;

	case "attackd": // ����

		/* �������˺���ȡ���ֵ��(�������ء�������ǳ)*/
		/* �����𻵶�������. ֻ�е�ǰ������ɱ���������� */

		if(me->query("race") == "Ұ��")	// Ұ�޵� damage ��ֱ���� apply ��
		{
			damage = me->query_temp("apply/damage");
			damage = damage/3 + random(to_int(damage/3*2));
			if(damage < 1)
				damage = 1;
		}

		else if(weapon)
		{
			w_damage = weapon->query("weapon_prop/damage");

			// ���������������
			if(mangle = weapon->query("weapon_mangle"))
				damage = w_damage*( (W_MAX_MANGLE - mangle)*100/W_MAX_MANGLE )/100;
			else
				damage = w_damage;
			damage = damage/3 + random(to_int(damage/3*2));

			// �б����������� 1 ���˺�
			if(damage < 1)
				damage = 1;
		}

		/* ��ʽ���˺��� */
		if(damage)
		{
			if(action["damage"])
				damage += action["damage"] * damage / 1000;

			// ��ʶ�����ڽ������ڷ��أ����л���ɸ�����˺���
			damage += damage*(me->query_cor())/1000;
		}

		wound = me->query_str();
		factor = me->query("force_factor");
		factor = (force = me->query("force"))>=factor?factor:force;

		// �ڹ�������˺���
		if(factor >=0)
		{
			if(force_skill = me->query_skill_mapped("force"))
			{
				foo = SKILL_D(force_skill)->hit_ob 
						(me, victim, wound, factor);
				if(stringp(foo))
				{
					if(!mute_flag)
						result += foo;
				}
				else if(intp(foo))
					wound += foo; 
			}
		}

		if(action["force"])
			wound += action["force"] * wound / 1000;

		if(martial_skill)
		{
			foo = SKILL_D(martial_skill)->hit_ob(me, victim, wound);
			if(stringp(foo))
			{
				if(!mute_flag)
					result += foo;
			}
			else if(intp(foo)) wound += foo;
		}

		// Let weapon or monster have their special damage.
		if(weapon) 
		{
			foo = weapon->weapon_effect(me, victim, wound);
			if(stringp(foo))
			{
				if(!mute_flag)
					result += foo;
			}
			else
				if(intp(foo))
					wound += foo;
		}
		else 
		{
			foo = me->hit_ob(victim, wound);

			if(stringp(foo))
			{
				if(!mute_flag)
					result += foo;
			}
			else
				if(intp(foo))
					wound += foo;
		}

		if( wound > 0)
			damage += (wound + random(wound))/2;
		if(damage < 0) damage = 0;

		// ������˺���Ӱ��
		exp = victim->query("combat_exp");
		if((exp+random(exp))/2 > me->query("combat_exp")) 
			damage -= damage / 4;

		// Ӳ���ķ������á�
		absp = skill_power(victim, "iron-cloth", SKILL_USAGE_ABSORB);
		if(absp)
		{
			defense_skill = victim->query_skill_mapped("iron-cloth");
			if(!defense_skill) defense_skill = "iron-cloth";

			if(!mute_flag)
				result += SKILL_D(defense_skill)->query_absorb_msg();
			foo = SKILL_D(defense_skill)->absorb_ob(victim, me, damage, absp);
			if(stringp(foo))
			{
				if(!mute_flag)
					result += foo;
			}
			else if(intp(foo)) damage += foo;
		}

		/* armor �����á�*/

		if(victim->query("race") == "Ұ��")	// Ұ�޵� armor ��ֱ���� apply ��
			armor = victim->query_temp("apply/armor");

		else if(mapp(fang_ju = victim->query_temp("armor")))
		{
			if( n = sizeof(armor_types = keys(fang_ju)) )
				for(i=0;i<n;i++)
					if((member_array(armor_types[i],armor_vs_limb[limb]) != -1)
					&& objectp(fang_ju[armor_types[i]]))
						armor += count_armor_protect(
							me,
							fang_ju[armor_types[i]],
							factor,
							weapon,
							w_damage);
		}

		if(armor)
		{
			armor = (random(armor) + armor)/2;
			if(armor < 1)
				armor = 1;
			damage -= armor;
			if(damage <0)
				damage = 0;
		}

		// �����˺�

		if( damage <= 0 )
		{
			if(!mute_flag)
				result += CYN"�����Ȼû������κ��˺�!\n"NOR;
		}
		else
		{
			victim->receive_damage("kee", damage, me );
			/* �б������ұ�����ɱ���������˸���1/4�������� */
			if(weapon && w_damage)
			{
				wound = damage/4;
				victim->receive_wound("kee", wound, me );
			}
			else
				wound = 0;

			if(!mute_flag)
				result += damage_msg(damage, action["damage_type"]);
		}

		break;
        }

	if(!mute_flag)
	{
		result = replace_string( result, "$l", limb );
		if( weapon_v )
			result = replace_string( result, "$v", weapon_v->name());
		if( victim->query_skill_mapped("iron-cloth"))
			result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));
	        if( objectp(weapon) )
	                result = replace_string( result, "$w", weapon->name() );
	        else 
			if( stringp(action["weapon"]) )
	                	result = replace_string( result, "$w", action["weapon"] );
	       		else 
				if( attack_skill == "finger" ) 
			              result = replace_string( result, "$w", "��ָ" );
		message_vision(result, me, victim);
	}

	/* ˫�����б���������мܿ���ζ��˫�������ཻ ��*/
	if( res == "parryd"
	&& weapon_v
	//&& weapon_v->query("skill_type") != "throwing"
	// ���������м�
	&& weapon )
	{
		w_action = weapon->query("actions");
		verbs = weapon->query("verbs");
		// �����������ж�
		if(w_action
		&& functionp(w_action["post_action"]) )
		{
			if( member_array( "throw" ,verbs) == -1)
				evaluate( w_action["post_action"], me, victim, weapon, damage);
		}

		else
		{
			w_action = (victim->query_temp("weapon"))->query("actions");
			verbs = (victim->query_temp("weapon"))->query("verbs");
			if(w_action
			&& member_array("throw",verbs) == -1
			&& functionp(w_action["post_action"]))
				evaluate( w_action["post_action"], me, victim, weapon, damage);
		}
	}
/*
        if(wizardp(me) && (string)me->query("env/combat")=="verbose") 
	{
                if( damage > 0 )
                        tell_object(me, sprintf(GRN 
				"AP��%d��DP��%d��PP��%d���˺�����%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(me, sprintf(GRN 
				"AP��%d��DP��%d��PP��%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }
	if(wizardp(victim) && (string)victim->query("env/combat")=="verbose")
	{
                if( damage > 0 )
                        tell_object(victim, sprintf(GRN 
				"AP��%d��DP��%d��PP��%d���˺�����%d���������ã�%d\n" NOR,
                                ap/100, dp/100, pp/100, damage,armor));
                else
                        tell_object(victim, sprintf(GRN 
				"AP��%d��DP��%d��PP��%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }
*/
	if(damage > 0) 
	{
		if(stringp(foo))
			report_status(me, 0);
                else
			report_status(victim, wounded);

                if(victim->is_busy())
			victim->interrupt_me(me);
                if((!me->is_killing(victim->query("id")))
		&& (!victim->is_killing(me->query("id")))
		&& ((victim->query("kee")*3 <= victim->query("max_kee"))
		|| (me->query("kee")*3 <= me->query("max_kee")))) 
		{
                        me->remove_enemy(victim);
                        victim->remove_enemy(me);
			if(stringp(foo))
			{
				message_vision(winner_msg[random(sizeof(winner_msg))], victim, me);
				winner_announce(victim, me);
			} else {
                        	message_vision(winner_msg[random(sizeof(winner_msg))], me, victim);
				winner_announce(me, victim);
			}
                }
        }
/*
        if(functionp(action["post_action"])  // �˵ط�ֻ�������ư���
	&& weapon
	&& arrayp(verbs = weapon->query("verbs"))
	&& member_array( "throw" ,verbs) != -1)
		evaluate( action["post_action"], me, victim, weapon, damage);
*/

	// ĳЩ��λ�������˺���
	if(res == "attackd" && damage)
	{
		switch(limb)
		{
			// ͷ�������˻���һЩ��
			case "ͷ��":
			case "����":
				damage /= 4;
				if(damage < 1)
					damage = 1;
				if(damage > 80)
					damage = 80;
				victim->receive_damage("sen",damage, me );
				pers = victim->query("sen")*100/victim->query("max_sen");
				if(pers <= 30)
					tell_object(victim,head_damage_me_msg[2]);
				else if(pers <= 70)
					tell_object(victim,head_damage_me_msg[1]);
				else
					tell_object(victim,head_damage_me_msg[0]);
				break;
			// ������Щ��λ�������ܵ��񵴡�
			case "�ؿ�":
			case "����":
			case "С��":
				if(victim->query("max_force") && victim->query("force"))
				{
					string report_limb_msg;

					damage /= 4;
					if(damage < 1)
						damage = 1;
					if(damage > 100)
						damage = 100;
					if(victim->query("force") <= damage)
						victim->set("force",0);
					else
						victim->add("force",-damage);
					if(damage <= 20)
						report_limb_msg = body_damage_me_msg[0];
					else if(damage <= 100)
						report_limb_msg = body_damage_me_msg[1];
					else
						report_limb_msg = body_damage_me_msg[2];
					report_limb_msg = replace_string( report_limb_msg, "$l", limb );
					tell_object(victim,report_limb_msg);
				}
				break;
		}
	}

	switch(res)
	{
		case "dodged":
			// dodge ����
			get_dodge_reward(me,victim);
			break;
	        case "parryd": // �м�
			// parry ����
			get_parry_reward(me,victim);
			break;
		case "attackd": // ����
			get_attack_reward(me,victim,attack_skill);
			break;
	}

        // �Ƿ���з���
        if( attack_type==TYPE_REGULAR	// ��������
	&& damage < 1			// û���ܵ��˺�
	&& victim->query_temp("is_guarding"))
	{
		victim->set_temp("is_guarding", 0);

		if(!victim->is_busy()		// û���� busy
		&& victim->query("kee")*100/victim->query("max_kee") >= 40
		&& random(victim->query_cor()) > (me->query_cor()/2))
                {
			if( !me->query("env/mute")
			&& !victim->query("env/mute")
			||(userp(me)&&userp(victim)))
				message_vision("$N��$n����ʧ�󣬳û�����������\n", victim, me);
			do_attack(victim, me, TYPE_RIPOSTE);
		}
	}

        if( attack_type==TYPE_REGULAR	// ��������
	&& damage > 1			// �ܵ��˺�
	&& random(me->query("kar")+victim->query("kar")) < me->query("kar")
	&& random(20) <= 10)
	{
		message_vision("\n$Nһ�����֣���ʤ׷������������\n",me);
		do_attack(me, victim, TYPE_RIPOSTE);
	}
}

// winner_announce(object ob1, object ob2)
void winner_announce(object ob1, object ob2)
{
	int month;
	object bbs, env;
	mapping note;
	mixed *local;
	string text;

	env = environment(ob1);
	if(!env->query("user_compare")) return;

	bbs = present("board", env);
	if(!bbs) return;

	local = localtime(time());
	month = local[4] + 1;
	note = allocate_mapping(4);
	note["title"] =CYN+  local[5] + "��" + month + "��" + local[3]
			+ "��" + local[2] + "ʱ" + local[1] + "��           "+NOR;
	note["author"] =YEL+ env->query("short")+NOR;
	note["time"] = time();
	text =ob1->short()+ RED"\n\tʤ\n"NOR + ob2->short();
	bbs->done_post(ob1, note, text);
	write("�������\n");
}


// fight()
void fight(object me, object victim)
{
	if( !living(me) )
		return;

	if( !me->visible(victim) && (random(100 + (int)me->query_skill("perception")) < 100) )
		return;

	// If victim is busy or unconcious, always take the chance to makeanattack.
	if( victim->is_busy() || !living(victim) )
	{
		me->set_temp("is_guarding", 0);
		if( !victim->is_fighting(me) )
			victim->fight_ob(me);
		do_attack(me, victim, TYPE_QUICK);
	}

	else if( random((int)victim->query("cor")*1.5) < (int)me->query_cor() )
	{
		me->set_temp("is_guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
			do_attack(me, victim, TYPE_REGULAR);
	}

	else
	{
		me->add_temp("is_guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
	}
}

//      auto_fight()
//
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	if(!me
	|| !obj
	|| !living(me)
	|| me->is_fighting(obj)
	|| (environment(me) != environment(obj))
	|| environment(me)->query(SAFE_ENV) )
		return;

	if( (type == "berserk") && !me->query_temp("looking_trouble") )
	{
		me->set_temp("looking_trouble", 1);
		message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);
	}

	// NPC
	if(!userp(obj)
	&& (obj->query(NO_KILL)
	|| obj->is_master()) )
		return;

	call_other(__FILE__, "start_" + type, me, obj );
}

// ɱ��
protected void start_berserk(object me, object obj)
{
	int bellicosity;

        bellicosity = (int)me->query("bellicosity");

	if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 )
		return;

	me->delete_temp("looking_trouble");
	if(me->query("can_speak"))
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
	me->kill_ob(obj);
	obj->kill_ob(me);
	if(userp(me) && userp(obj))
		obj->accept_first_kill(me);
}

// ���
protected void start_hatred(object me, object obj)
{
	if(me->query("can_speak"))
		message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
        me->kill_ob(obj);
	obj->kill_ob(me);
}

// ɱ��
protected void start_vendetta(object me, object obj)
{
        me->kill_ob(obj);
}

// �Զ�ɱ��
protected void start_aggressive(object me, object obj)
{
        me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
        switch(event) {
                case "dead":
                        message_vision("\n$N���ˡ�\n\n", ob);
                        break;
                case "unconcious":
                        message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N���������۾��������˹�����\n\n", ob);
                        break;
        }
}

void winner_reward(object killer, object victim)
{
        killer->defeated_enemy(victim);
}

int pk_gain(int exp)
{
	if(exp < 500000)
		return exp/150;
	else if(exp<1000000)
		return exp/200;
	else
		return exp/300;
}

int nk_gain(int exp)
{
	if(exp < 10000)		// ������������.
		return exp/30;
	if(exp < 100000)
		return exp/50;
	if(exp < 500000)
		return exp/120;
	if(exp < 1000000)
		return exp/200;
	else
		return exp/400;
}

protected int team_exp(object who)
{
	object *memb;
	int i, n, exp;

	if(!who || !(n=sizeof(memb = who->query_team_member())))
		return 0;

	for(i=0;i<n;i++)
		exp += memb[i]->query("combat_exp");

	exp /= n;

	return exp;
}

protected void team_gain(object me,string name, int gain)
{
	object *memb;
	int i,n, sum;

	if(!objectp(me)
	|| !stringp(name)
	|| (gain <= 0) )
		return;

	if(!n = sizeof(memb = me->query_team_member()))
		return;

	for(i=0;i<n;i++)
		sum += memb[i]->query("combat_exp");

	for(i=0;i<n;i++)
	{
		float temp = to_float(memb[i]->query("combat_exp"));
		int e = temp/sum*gain;

		if(e < 1)
			e = 1;

		tell_object(memb[i],sprintf("�����ڵĶ���ɱ��%s����ֵ�%d�㾭�顣\n\n",name,e));
		memb[i]->add("combat_exp",e);
	}
}

protected int array_exp(object who)
{
	int i,n,exp;
	object *memb;

	if(!objectp(who))
		return 0;

	if(!n = sizeof(memb = who->query_array_member()))
		return 0;

	for(i=0;i<n;i++)
		exp += memb[i]->query("combat_exp");

	exp /= n;

	return exp;
}

protected void array_gain(object me,string name,int gain,int exp)
{
	object *memb;
	int i,n, sum;
	string a_name;

	if(!objectp(me)
	||!stringp(name)
	|| (gain <= 0)
	|| (exp <= 0)
	|| (!a_name = me->query_array_name()) )
		return;

	if(!n = sizeof(memb = me->query_array_member()))
		return;

	for(i=0;i<n;i++)
		sum += memb[i]->query("combat_exp");

	gain *= 1.2;

	for(i=0;i<n;i++)
	{
		float temp = to_float(memb[i]->query("combat_exp"));
		int e = temp/sum*gain;

		if(e < 1)
			e = 1;

		tell_object(memb[i],sprintf("��%s��ɱ��%s����ֵ�%d�㾭�顣\n\n",
			a_name,name,e));
		memb[i]->add("combat_exp",e);
	}
}

// Modified by Find.
void killer_reward(object victim)
{
	int gain = 0, pass, valid;
	string vmark;
	mapping quest;
	int exp, k_exp;
	object killer,kyun;
	string damage_type,news;

	exp = victim->query("combat_exp");

	killer = victim->query_temp("last_damage_from");
	if(objectp(killer))
	{
		victim->set_temp("my_killer", killer->query("id"));
		k_exp = killer->query("combat_exp");

		if(!victim->query("no_gain_bellicosity"))
		{
			if(userp(killer))
			{
				if( (exp > k_exp/2) && (exp < k_exp*2) )
					killer->add("bellicosity", 30 );
			}
			else if(killer->query("bellicosity") < 100)
				killer->add("bellicosity", 2 );
		}
	}

        if( userp(victim) )
	{
		victim->clear_condition();
		victim->set("bellicosity", 0);
		victim->delete("vendetta");

		if(objectp(killer))
		{
			killer->add("PKS", 1);
			if(userp(killer))
				victim->add("BPKS",1);
			else
				victim->add("BMKS",1);

			victim->delete_temp("last_damage_from");

			valid = valid_killer(victim, killer);

			if(environment(killer)->query("user_compare") && userp(killer))
			{
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s�ڱ����б�%sɱ���ˡ�", victim->name(1), 
					killer->name(1)));
				victim->delete_temp("damage_type");
				return;
			}

			if(userp(killer) && killer->in_array() && killer->query_array_status())
			{
				object *memb;
				mapping ey;

				memb = killer->query_array_member();

				foreach(object ttmp in memb)
				{
					if(ttmp
					&& mapp(ey = ttmp->query("enyi_class"))
					&& sizeof(ey)
					&& !ey["finish"]
					&& (ey["id"] == geteuid(victim)) )
					{
						pass = 1;
						ttmp->set("enyi_class/finish", geteuid(victim));
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��������ׯ�������ˡ�",
								victim->name(1)));
						news = sprintf("%s(%s)������ׯ�������ˣ���\n",
							victim->name(1));
						break;
					}
				}

				if(!pass)
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s��%s����ġ�%s��ɱ���ˡ�",
							victim->name(1),
							killer->query_array_master()->name(1),
							killer->query_array_name()));
					news = sprintf("%s(%s)��%s(%s)����ġ�%s������������\n",
						victim->name(1),
						capitalize(victim->query("id")),
						killer->query_array_master()->name(1),
						capitalize(killer->query_array_master()->query("id")),
						killer->query_array_name());

					if(valid)
						victim->set("my_killer", geteuid(killer));
				}
			}

			else if(userp(killer) && killer->in_team())
			{
				object *memb;
				mapping ey;

				memb = killer->query_team_member();

				foreach(object ttmp in memb)
				{
					if(ttmp
					&& mapp(ey = ttmp->query("enyi_class"))
					&& sizeof(ey)
					&& !ey["finish"]
					&& (ey["id"] == geteuid(victim)) )
					{
						pass = 1;
						ttmp->set("enyi_class/finish", geteuid(victim));
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��������ׯ�������ˡ�",
								victim->name(1)));
						news = sprintf("%s(%s)������ׯ�������ˣ���\n",
							victim->name(1));
						break;
					}
				}

				if(!pass)
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s��%s����Ķ���ɱ���ˡ�",
							victim->name(1),
							killer->query_team_leader()->name(1)));
					news = sprintf("%s(%s)��%s(%s)����Ķ�������������\n",
						victim->name(1),
						capitalize(victim->query("id")),
						killer->query_team_leader()->name(1),
						capitalize(killer->query_team_leader()->query("id")));
					if(valid)
						victim->set("my_killer", geteuid(killer));
				}
			}

			else
			{
				mapping ey;

				if(userp(killer))
				{
					if(mapp(ey = killer->query("enyi_class"))
					&& sizeof(ey)
					&& !ey["finish"]
					&& (geteuid(victim) == ey["id"]) )
					{
						pass = 1;
						killer->set("enyi_class/finish", geteuid(victim));
						CHANNEL_D->do_channel(this_object(), "rumor",
							sprintf("%s��������ׯ�������ˡ�", victim->name(1)));
						news = sprintf("%s(%s) ��������ׯ�������ˣ���\n",
							victim->name(1),capitalize(victim->query("id")) );
					}
					else
					{
						news = sprintf("%s(%s) �� %s(%s) ����������\n",
							victim->name(1),capitalize(victim->query("id")),
							killer->name(1),
							capitalize(killer->query("id")) );
						if(valid)
							victim->set("my_killer", geteuid(killer));
					}
				}

				if(!pass)
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s��%sɱ���ˡ�", victim->name(1), killer->name(1)));
			}

			if(userp(killer) && !pass)
			{
				object *memb;

				if( killer->in_array() )
					memb = killer->query_array_member();
				else if(killer->in_team())
					memb = killer->query_team_member();
				else if(valid)
					check_pker( victim, killer );

				if(sizeof(memb) && valid)
					foreach(object ttmp in memb)
						check_pker( victim, ttmp );
			}

			player_was_die(victim,killer,pass);
			victim->save();
		}

		else
		{
			damage_type = victim->query_temp("damage_type");
			victim->delete_temp("damage_type");
			player_was_die(victim,damage_type);
			victim->add("BMKS",1);
			victim->save();
			switch (damage_type)
			{
			case "bleeding":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s���ϵ��˿�Ѫ����ֹ������", victim->name()));
				break;
			case "poison":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s���������ˡ�", victim->name()));
/*
				news = sprintf("%s(%s)�ж�ҽ�β��������������ˣ���\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "illness":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s�ز����ζ�����", victim->name()));
/*
				news = sprintf("%s(%s)�ز����ζ�������\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "tire":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s�������Ĺ��ȣ������ˡ�", victim->name()));
/*
				news = sprintf("%s(%s)�������Ĺ��ȣ���������ˣ���\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "hunger":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%sû��û�ȣ��������ȶ�����", victim->name()));
/*
				news = sprintf("%s(%s)û��û�ȣ��������ȶ�������\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "trip":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s�����ˤ���ˡ�", victim->name()));
/*
				news = sprintf("%s(%s)�����ˤ���ˣ���\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			default:
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%sĪ����������ˡ�", victim->name()));
/*
				news = sprintf("%s(%s)һ��ûע�⣬Ī��������뿪����������\n",
					victim->name(),capitalize(victim->query("id")));
*/
			}
		}
		if(news)
			NEWS_D->add_news_item( news , "p", 1 );
	}

/*
	if(killer && userp(killer) && (userp(victim) || victim->is_master()))
		CRIME_D->pass_family_crime(killer,victim);
*/
	if(killer && userp(killer) && stringp(vmark = victim->query("vendetta_mark")) )
               	killer->add("vendetta/" + vmark, 1);

	if(killer && userp(killer) && victim->is_doctor() )
		killer->set("doctor/kill_doctor",time()+72*3600);
	/* ɱ���� doctor,����72Сʱ�ò���ҽ��. �� DOCTOR ���.*/

	/* �˴�Ϊ��ֹһ���˰�����������һ����ɱ�� ����ȡ�ɷ���. */
	kyun = victim->query_temp("k_unconcious");

	if( killer
	&& objectp(kyun)
	&& (kyun != killer)
	&& (!killer->in_team() || !killer->is_team_member(kyun))
	&& (!killer->query_array_status() || !killer->is_array_member(kyun))
	)
		killer = 0;

	if(killer)
	{
		if(!userp(victim))
			killer->add("MKS", 1);

		if(userp(killer) && interactive(killer))
		{
			string clas;

			if( (clas = killer->query("class"))
			&& mapp(quest = killer->query(sprintf("quest/%s_quest",clas)))
			&& quest["quest"] == "ɱ"
			&& victim->query("name") == quest["name"]
			&& !userp(victim) )
				killer->set(sprintf("quest/%s_quest/killed",clas),1 );

			if(userp(killer)
			&& killer->in_array()
			&& killer->query_array_status())
				k_exp = array_exp(killer);

			if(userp(killer)
			&& killer->in_team() )
				k_exp = team_exp(killer);

			if(userp(victim))
			{
				if(!environment(killer)->query("user_compare")
				&& k_exp/100*85 < exp && k_exp*1.5 > exp)
					gain = pk_gain(exp);
			}

			else if( !victim->query("no_exp_gain") && exp && (exp < k_exp*2) )
			{
				gain = nk_gain(exp);
				if(exp < k_exp/2)
					gain /= to_int(ceil(k_exp/exp))*2;
				if(gain < 1)
					gain = 1;
			}

			if(gain)
			{
				if(userp(killer)
				&& killer->in_array()
				&& killer->query_array_status())
					array_gain(killer,victim->name(),gain,k_exp);

				else if(userp(killer)
				&& killer->in_team() )
					team_gain(killer,victim->name(),gain);

				else
				{
					tell_object(killer,sprintf("��ɱ��%s�õ���%s��ʵս���顣\n\n",
						victim->name(),chinese_number(gain)));
					killer->add("combat_exp",gain);
					//killer->save();
				}
			}

			// gongji ����
			if( killer->query("class")
			&& killer->query("class") == victim->query("class"))
			{
				if(userp(victim))
				{
					killer->add("family/gongji",-500);
					tell_object(killer,sprintf("������к�ͬ�ŵ��ӣ�ʦ�Ź����½� %d �㡣\n",500));
				}
				else
				{
					if(killer->is_apprentice_of(victim))
					{
						killer->add("family/gongji",-1000);
						tell_object(killer,sprintf("������ʦ�������Ϊ��ʦ�Ź����½� %d �㡣\n",1000));
					}
					else if( killer->query("family/generation") >
					victim->query("family/generation") )
					{
						killer->add("family/gongji",-600);
						tell_object(killer,sprintf("������к�ͬ���𳤣�ʦ�Ź����½� %d �㡣\n",600));
					}
					else
					{
						killer->add("family/gongji",-300);
						tell_object(killer,sprintf("������к�ͬ�ţ�ʦ�Ź����½� %d �㡣\n",300));
					}
				}
			}
		}
	}
}
 
varargs protected void player_was_die(object user, mixed ob, int ry_flag)
{
	int pot,exp,time;
	string reason;
	mapping death;

	if(!user)
		return;

	if(ry_flag)
	{
		//user->skill_death_penalty();
		user->skill_death_penalty();
	}

	user->skill_death_penalty();

	exp = (int)user->query("combat_exp")/20;
	if(ry_flag)
		exp *= 2;
	user->add("combat_exp", -exp);

	if(ry_flag)
		user->set("potential", user->query("learned_points"));
	else if( (pot = (int)user->query("potential") - (int)user->query("learned_points")) > 0 )
		user->add("potential",-pot/2);

	if(objectp(ob))
	{
		time = time();
		if( !mapp(death = user->query("death")) || !sizeof(death) )
			death = (["num":1, "time":time()]);
		else
		{
			if( time - death["time"] > 600 )
			{
				death["num"] = 1;
				death["time"] = time;
			}
			else
				death["num"]++;
			
		}

		user->set("death",death);

		log_file("player_die",sprintf("%s(%s) �� %s �� %s%s ɱ���ˡ�\n",
			user->name(1),user->query("id"),ctime(time()),
			(userp(ob))?ob->name(1):"NPC",
			(userp(ob))?"("+ob->query("id")+")":""));
	}

	else
	{
		switch(ob)
		{
			case "poison":
				reason = "��������";
				break;
			case "illness":
				reason="�ز����ζ���";
				break;
			case "tire":
				reason="�������Ĺ��ȣ�������";
				break;
			case "hunger":
				reason="û��û�ȣ��������ȶ���";
				break;
			case "trip":
				reason="�����ˤ����";
				break;
			default:
				reason="Ī�����������";
		}
		log_file("player_die",sprintf("%s(%s) �� %s %s��\n",
			user->name(1),user->query("id"),ctime(time()),reason));
	}

	log_file("player_die",sprintf("\tlost exp: %d, potential: %d.\n",exp,pot/2));
}
