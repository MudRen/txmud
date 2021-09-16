// weapond.c
// Modified by Find.

#include <ansi.h>
#include <combat.h>
#include <weapon.h>
#include <mangle.h>

protected int query_rigidity(object weapon);

protected mapping weapon_actions = ([
	"slash": ([	/* �Ϳ� */
		"damage_type":	"����",
		"action":	"$N�Ӷ�$w��ն��$n��$l",
		"parry":	20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"slice": ([	/* �� */
		"damage_type":  "����",
		"action":	"$N��$w��$n��$l��ȥ",
		"dodge":	20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"chop": ([	/* �� */
		"damage_type":	"����",
		"action":	"$N��$w����$n��$l������ȥ",
		"parry":	-20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"hack": ([	/* �� */
		"damage_type":  "����",
		"action":	"$N����$w����׼$n��$lһ���ҿ�",
		"damage":	30,
		"dodge":	30,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"thrust": ([	/* �� */
		"damage_type":  "����",
		"action":	"$N��$w��$n��$l��ȥ",
		"dodge":	15,
		"parry":	-15,
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"pierce": ([	/* ���ơ�ͱ */
		"damage_type":  "����",
		"action":	"$N��$w��$n��$l�ݺݵ�һͱ",
		"dodge":	-30,
		"parry":	-30,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"whip": ([	/* ��� */
		"damage_type":  "����",
		"action":	"$N��$wһ���$n��$l��ȥ",
		"dodge":	-20,
		"parry":	30,
                ]),
	"impale": ([	/* �̴� */
		"damage_type":  "����",
		"action":	"$N��$w��$n��$lֱ����ȥ",
		"dodge":	-10,
                "parry":	-10,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"bash": ([	/* �ͻ� */
		"damage_type":	"����",
		"action":	"$N����$w����$n��$l����һ��",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"crush": ([	/* ѹ�顢���� */
		"damage_type":  "����",
		"action":	"$N�߸߾���$w����$n��$l��ͷ����",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"slam": ([	/* ײ�� */
		"damage_type":  "����",
		"action":	"$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"throw": ([	/* �� */
		"damage_type":  "����",
		"action":	"$N��$w��׼$n��$l���˹�ȥ",
		"post_action":  (: call_other, __FILE__, "throw_weapon" :),
		]),
]);

protected mapping weapon_base_value = ([
"axe" : 2500,
"blade" : 2500,
"dagger" : 500,
"hammer" : 4000,
"dhammer" : 3000,
"fork" : 3000,
"stick" : 3000,
"sword" : 2500,
"whip" : 3000,
]);

protected mapping weapon_base_weight = ([
"axe" : 8000,
"blade" : 7000,
"dagger" : 1000,
"hammer" : 12000,
"dhammer" : 9000,
"fork" : 8000,
"stick" : 8000,
"sword" : 7000,
"throwing" : 100,
"whip" : 8000,
]);

protected mapping weapon_base_damage = ([
"axe" : 25,
"blade" : 25,
"dagger" : 10,
"hammer" : 30,
"dhammer" : 25,
"fork" : 25,
"stick" : 25,
"sword" : 25,
"throwing" : 6,
"whip" : 25,
]);

void create()
{
	seteuid(getuid());
}

mapping query_action()
{
	string verb, *verbs;

	verbs = previous_object()->query("verbs");

	if( !pointerp(verbs) )
		return weapon_actions["hit"];
	else
	{
		verb = verbs[random(sizeof(verbs))];
		if( !undefinedp(weapon_actions[verb]) )
			return weapon_actions[verb];
		else return weapon_actions["hit"];
	}
//  return weapon_actions[random(sizeof(weapon_actions))];  
}


void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) )
	{
		if( (int)weapon->query_amount()==1 )
		{
			weapon->unequip();
			tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
		}
		weapon->add_amount(-1);
	}
}

/*
 * ����Ӧ����һ���𻵶ȣ��������������ӱ������𻵶ȣ�
 * �����̿��ԶԱ��������޲���ʹ֮�ָ����¡�
 * �𻵶� 0 - 100(���ֵ�ɵ�), set("weapon_mangle",int);
 * �ﵽ���ֵ����ȫ���ˣ�����ϵ��ġ�����
 * 0 ȫ�¡�
 * �������𻵶�Ӱ�������ɱ�������ɰٷֱȵݼ���
 * ��Ȼ���� value.
 */
void bash_weapon(object me, object victim, object weapon, int damage)
{
	object v_weapon;
	int wap, wpp;
	int weight_me,weight_v;
	int str_me,str_v;
	int ff_me,ff_v;
	int exchange = 0,temp,flag = 0;
	int rig_me,rig_v,mar;
	int count,count_max;

	/* ������ײ����������һ���Ǳ������ķ� 
	   �������Ӱ��������У�
		��������
		˫������
		enforce
		�����������(kee)

	   ��һ��Ϊ�������𻵣�Ӱ�������У�
		��������(ֻ��˫�����������������ʱ��������)
		�����ʵ�
		enforce
	*/

	if(!objectp(weapon))
		return;
	if(!objectp(v_weapon = victim->query_temp("weapon")))
		return;

	weight_me = weapon->weight();
	weight_v = v_weapon->weight();
	str_me = me->query("str");
	str_v = victim->query("str");
	ff_me = (me->query("force")>=me->query("force_factor"))?
		me->query("force_factor"):0;
	ff_v = (victim->query("force")>=victim->query("force_factor"))?
		victim->query("force_factor"):0;

						/* ����������� */
	wap = weight_me/100 + str_me + ff_me + me->query("kee")*100/me->query("max_kee");
	wpp = weight_v/100 + str_v + ff_v + victim->query("kee")*100/victim->query("max_kee");

	if(wap < wpp)
	{
		temp = wap;
		wap = wpp;
		wpp = temp;
		exchange = 1;
	}

	if(!exchange)
	{
		count = victim->query_temp("weapon_fly_count");
		count_max = (victim->query("combat_exp")/victim->query("max_kee")*victim->query("kee"))%200000;
	}
	else
	{
		count = me->query_temp("weapon_fly_count");
		count_max = (me->query("combat_exp")/me->query("max_kee")*me->query("kee"))%200000;
	}

	if(count_max < 1)
		count_max = 1;
	if(count_max > 5)
		count_max = 5;

	temp = (wap - wpp)*100/wap;
	if(temp >= 50)
	{
		if(random(100) < 40) /* �� 40% �Ŀ����Ա���� */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N����û��ڷ��飬" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"���ַ��˳�ȥ��\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N����û��ڷ��飬���е�" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"��Щ���֡�\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->set_temp("weapon_fly_count",count);
			}

			if(flag)
			{
				if(!exchange)
				{
					v_weapon->unequip();
					v_weapon->move(environment(victim));
					victim->reset_action();
				}

				else
				{
					weapon->unequip();
					weapon->move(environment(me));
					me->reset_action();
				}
			}
		}
		else
			message_vision(HIY "$N��" + weapon->name() + "��$n��" + v_weapon->name()
			+ "�����ð�����Ļ��ǡ�\n" NOR, me, victim);
	}

	else if(temp >= 30 && temp <50)
	{
		if(random(100) < 20) /* �� 20% �Ŀ����Ա���� */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N����û��ڷ��飬" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"���ַ��˳�ȥ��\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N����û��ڷ��飬���е�" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"��Щ���֡�\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->set_temp("weapon_fly_count",count);
			}

			if(flag)
			{
				if(!exchange)
				{
					v_weapon->unequip();
					v_weapon->move(environment(victim));
					victim->reset_action();
				}

				else
				{
					weapon->unequip();
					weapon->move(environment(me));
					me->reset_action();
				}
			}
		}

		else
			message_vision(HIY "$N��" + weapon->name() + "��$n��" + v_weapon->name()
			+ "�����ð�����Ļ��ǡ�\n" NOR, me, victim);
	}

	else if(temp >= 10 && temp <30)
	{
		if(random(100) < 10) /* ֻ�� 10% �Ŀ����Ա���� */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N����û��ڷ��飬" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"���ַ��˳�ȥ��\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N����û��ڷ��飬���е�" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"��Щ���֡�\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->set_temp("weapon_fly_count",count);
			}

			if(flag)
			{
				if(!exchange)
				{
					v_weapon->unequip();
					v_weapon->move(environment(victim));
					victim->reset_action();
				}

				else
				{
					weapon->unequip();
					weapon->move(environment(me));
					me->reset_action();
				}
			}
		}

		else
			message_vision(HIY "$N��" + weapon->name() + "��$n��" + v_weapon->name()
			+ "�����ð�����Ļ��ǡ�\n" NOR, me, victim);
	}

	else
		message_vision(HIY "$N��" + weapon->name() + "��$n��" + v_weapon->name()
		+ "�����ð�����Ļ��ǡ�\n" NOR, me, victim);

	if(!flag)
	{
		if(weight_me > weight_v ) /* ���������������⣬�����һ���𺦡�*/
		{
			if( weight_v *2.5 <= weight_me)
			{
				mar = v_weapon->query("weapon_mangle");
				v_weapon->set("weapon_mangle",(++mar>=W_MAX_MANGLE)?
					W_MAX_MANGLE:mar);
			}
		}

		else
		{
			if( weight_me *2.5 <= weight_v)
			{
				mar = weapon->query("weapon_mangle");
				weapon->set("weapon_mangle",(++mar>=W_MAX_MANGLE)?W_MAX_MANGLE:mar);
			}
		}

		rig_me = query_rigidity(weapon);	/* ȡ������Ӳ��ֵ��*/
		rig_v = query_rigidity(v_weapon);

		mar = rig_me - rig_v;  /* Ӳ�Ȳ� */
		if(abs(mar) >= 4)
			mar = mar/2 + (mar<0)? -random(abs(mar)/2):random(abs(mar)/2);

		mar += (ff_me - ff_v)/20;	/* enforce �����𻵶� */

		if(mar > 0)
		{
			temp = v_weapon->query("weapon_mangle");
			v_weapon->set("weapon_mangle",(mar+temp>=W_MAX_MANGLE)?
				W_MAX_MANGLE:(mar+temp));

		}

		else if(mar <0)
		{
			temp = weapon->query("weapon_mangle");
			weapon->set("weapon_mangle",(-mar+temp>=W_MAX_MANGLE)?
				W_MAX_MANGLE:(-mar+temp));
		}

		else	/* ����൱������һ���𻵶� */
		{
			weapon->add("weapon_mangle",1);
			v_weapon->add("weapon_mangle",1);
		}
	}

	if(weapon->query("weapon_mangle") >= W_MAX_MANGLE)
	{
		message_vision(HIB "ֻ������ž����һ����$N���е�" + weapon->name()
                               + "�Ѿ���Ϊ���أ�\n" NOR, me );
		weapon->unequip();
		weapon->move(environment(me));
		me->reset_action();
	}

	if(v_weapon->query("weapon_mangle") == W_MAX_MANGLE)
	{
		message_vision(HIB "ֻ������ž����һ����$N���е�" + v_weapon->name()
                               + "�Ѿ���Ϊ���أ�\n" NOR, victim );
		v_weapon->unequip();
		v_weapon->move(environment(me));
		victim->reset_action();
	}
}

int query_rigidity(object weapon)	/* ��Ӳ�� */
{
	if(!weapon || !objectp(weapon))
		return 0;

	switch (weapon->query("material"))
	{
		case "black_iron":	/* ���� �ǳ�����! */
			return 60;
		case "steel":		/* �� */
			return 38;
		case "iron":		/* �� */
			return 30;
		case "copper":		/* ͭ */
			return 28;
		case "stone":		/* ʯ */
			return 26;
		case "gold":		/* �� */
			return 25;
		case "silver":		/* �� */
			return 24;
		case "skin":		/* Ƥ */
			return 20;
		case "bone":		/* �� */
			return 18;
		case "bamboo":		/* �� */
			return 15;
		case "wood":		/* ľ */
			return 14;

		default:
			return 5;
	}
}

int query_weapon_base_damage(object ob)
{
	string cls;

	if(!ob || !ob->is_weapon() || !(cls = ob->query("skill_type")))
		return 0;

	if( (cls == "hammer") && (ob->query("flag") & SECONDARY) )
		cls = "dhammer";

	if(undefinedp(weapon_base_damage[cls]))
		return 0;
	else
		return weapon_base_damage[cls];
}

int query_weapon_base_value(object ob)
{
	string cls;

	if(!ob || !ob->is_weapon() || !(cls = ob->query("skill_type")))
		return 0;

	if( (cls == "hammer") && (ob->query("flag") & SECONDARY) )
		cls = "dhammer";

	if(undefinedp(weapon_base_value[cls]))
		return 0;
	else
		return weapon_base_value[cls];
}

int query_weapon_base_weight(object ob)
{
	string cls;

	if(!ob || !ob->is_weapon() || !(cls = ob->query("skill_type")))
		return 0;

	if( (cls == "hammer") && (ob->query("flag") & SECONDARY) )
		cls = "dhammer";

	if(undefinedp(weapon_base_weight[cls]))
		return 0;
	else
		return weapon_base_weight[cls];
}

int query_self_weapon_weight(object ob)
{
	int bweight, bdamage, damage, n;

	if(!(bweight = query_weapon_base_weight(ob))
	|| !(bdamage = query_weapon_base_damage(ob)) )
		return 0;

	damage = ob->query("weapon_prop/damage") - bdamage;
	if(damage <= 0)
		return bweight;

	n = damage*damage*5/2;
	if(n > 30000)
		n = 30000;
	return n + bweight;
}

int query_self_weapon_value(object ob)
{
	int bvalue, bdamage, damage;

	if(!(bvalue = query_weapon_base_value(ob))
	|| !(bdamage = query_weapon_base_damage(ob)) )
		return 0;

	damage = ob->query("weapon_prop/damage");
	if(damage - bdamage <= 0)
		return bvalue;
	else
		return (damage - bdamage)*100 + bvalue;
}
