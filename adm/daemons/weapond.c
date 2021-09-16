// weapond.c
// Modified by Find.

#include <ansi.h>
#include <combat.h>
#include <weapon.h>
#include <mangle.h>

protected int query_rigidity(object weapon);

protected mapping weapon_actions = ([
	"slash": ([	/* 猛砍 */
		"damage_type":	"割伤",
		"action":	"$N挥动$w，斩向$n的$l",
		"parry":	20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"slice": ([	/* 切 */
		"damage_type":  "砍伤",
		"action":	"$N用$w往$n的$l砍去",
		"dodge":	20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"chop": ([	/* 剁 */
		"damage_type":	"劈伤",
		"action":	"$N的$w朝著$n的$l劈将过去",
		"parry":	-20,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"hack": ([	/* 砍 */
		"damage_type":  "砍伤",
		"action":	"$N挥舞$w，对准$n的$l一阵乱砍",
		"damage":	30,
		"dodge":	30,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"thrust": ([	/* 刺 */
		"damage_type":  "刺伤",
		"action":	"$N用$w往$n的$l刺去",
		"dodge":	15,
		"parry":	-15,
		"post_action":  (: call_other, __FILE__, "bash_weapon" :),
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"pierce": ([	/* 刺破、捅 */
		"damage_type":  "刺伤",
		"action":	"$N的$w往$n的$l狠狠地一捅",
		"dodge":	-30,
		"parry":	-30,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
		]),
	"whip": ([	/* 抽打 */
		"damage_type":  "鞭伤",
		"action":	"$N将$w一扬，往$n的$l抽去",
		"dodge":	-20,
		"parry":	30,
                ]),
	"impale": ([	/* 刺穿 */
		"damage_type":  "刺伤",
		"action":	"$N用$w往$n的$l直戳过去",
		"dodge":	-10,
                "parry":	-10,
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"bash": ([	/* 猛击 */
		"damage_type":	"挫伤",
		"action":	"$N挥舞$w，往$n的$l用力一□",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"crush": ([	/* 压碎、砸碎 */
		"damage_type":  "挫伤",
		"action":	"$N高高举起$w，往$n的$l当头砸下",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"slam": ([	/* 撞击 */
		"damage_type":  "挫伤",
		"action":	"$N手握$w，眼露凶光，猛地对准$n的$l挥了过去",
		"post_action":	(: call_other, __FILE__, "bash_weapon" :),
                ]),
	"throw": ([	/* 抛 */
		"damage_type":  "刺伤",
		"action":	"$N将$w对准$n的$l射了过去",
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
			tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
		}
		weapon->add_amount(-1);
	}
}

/*
 * 兵器应该有一个损坏度，经常磕碰会增加兵器的损坏度，
 * 铁匠铺可以对兵器进行修补，使之恢复如新。
 * 损坏度 0 - 100(最大值可调), set("weapon_mangle",int);
 * 达到最大值就完全坏了，比如断掉的。。。
 * 0 全新。
 * 兵器的损坏度影响兵器的杀伤力，成百分比递减。
 * 当然还有 value.
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

	/* 兵器碰撞有两种现象，一种是兵器被磕飞 
	   这种情况影响的因素有：
		兵器重量
		双方臂力
		enforce
		体力消耗情况(kee)

	   另一种为兵器的损坏，影响因素有：
		兵器重量(只有双方兵器重量很悬殊的时候起作用)
		兵器质地
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

						/* 体力消耗情况 */
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
		if(random(100) < 40) /* 有 40% 的可能性被打飞 */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N被震得虎口发麻，" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"脱手飞了出去！\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N被震得虎口发麻，手中的" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"险些脱手。\n" NOR,(!exchange)?victim:me);
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
			message_vision(HIY "$N的" + weapon->name() + "和$n的" + v_weapon->name()
			+ "相击，冒出点点的火星。\n" NOR, me, victim);
	}

	else if(temp >= 30 && temp <50)
	{
		if(random(100) < 20) /* 有 20% 的可能性被打飞 */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N被震得虎口发麻，" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"脱手飞了出去！\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N被震得虎口发麻，手中的" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"险些脱手。\n" NOR,(!exchange)?victim:me);
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
			message_vision(HIY "$N的" + weapon->name() + "和$n的" + v_weapon->name()
			+ "相击，冒出点点的火星。\n" NOR, me, victim);
	}

	else if(temp >= 10 && temp <30)
	{
		if(random(100) < 10) /* 只有 10% 的可能性被打飞 */
		{
			count++;
			if(count >= count_max)
			{
				message_vision(HIR "$N被震得虎口发麻，" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"脱手飞了出去！\n" NOR,(!exchange)?victim:me);
				((!exchange)?victim:me)->delete_temp("weapon_fly_count");
				flag = 1;
			}

			else
			{
				message_vision(HIM "$N被震得虎口发麻，手中的" + ((!exchange)?
					v_weapon->name():weapon->name()) +
					"险些脱手。\n" NOR,(!exchange)?victim:me);
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
			message_vision(HIY "$N的" + weapon->name() + "和$n的" + v_weapon->name()
			+ "相击，冒出点点的火星。\n" NOR, me, victim);
	}

	else
		message_vision(HIY "$N的" + weapon->name() + "和$n的" + v_weapon->name()
		+ "相击，冒出点点的火星。\n" NOR, me, victim);

	if(!flag)
	{
		if(weight_me > weight_v ) /* 兵器重量过于悬殊，会造成一点损害。*/
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

		rig_me = query_rigidity(weapon);	/* 取兵器的硬度值。*/
		rig_v = query_rigidity(v_weapon);

		mar = rig_me - rig_v;  /* 硬度差 */
		if(abs(mar) >= 4)
			mar = mar/2 + (mar<0)? -random(abs(mar)/2):random(abs(mar)/2);

		mar += (ff_me - ff_v)/20;	/* enforce 修正损坏度 */

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

		else	/* 旗鼓相当各增加一点损坏度 */
		{
			weapon->add("weapon_mangle",1);
			v_weapon->add("weapon_mangle",1);
		}
	}

	if(weapon->query("weapon_mangle") >= W_MAX_MANGLE)
	{
		message_vision(HIB "只听见「啪」地一声，$N手中的" + weapon->name()
                               + "已经断为两截！\n" NOR, me );
		weapon->unequip();
		weapon->move(environment(me));
		me->reset_action();
	}

	if(v_weapon->query("weapon_mangle") == W_MAX_MANGLE)
	{
		message_vision(HIB "只听见「啪」地一声，$N手中的" + v_weapon->name()
                               + "已经断为两截！\n" NOR, victim );
		v_weapon->unequip();
		v_weapon->move(environment(me));
		victim->reset_action();
	}
}

int query_rigidity(object weapon)	/* 坚硬度 */
{
	if(!weapon || !objectp(weapon))
		return 0;

	switch (weapon->query("material"))
	{
		case "black_iron":	/* 玄铁 非常厉害! */
			return 60;
		case "steel":		/* 钢 */
			return 38;
		case "iron":		/* 铁 */
			return 30;
		case "copper":		/* 铜 */
			return 28;
		case "stone":		/* 石 */
			return 26;
		case "gold":		/* 金 */
			return 25;
		case "silver":		/* 银 */
			return 24;
		case "skin":		/* 皮 */
			return 20;
		case "bone":		/* 骨 */
			return 18;
		case "bamboo":		/* 竹 */
			return 15;
		case "wood":		/* 木 */
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
