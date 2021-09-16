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

// hand_flag 0 表示右手出招, 1 表示左手出招.
static int hand_flag = 0;

/*这些部位一般为武者严加保护的地方，向这些部位
 *进攻成功的可能性减小，一但得手被攻者所受的伤
 *害也相对较大。
 */
string *danger_limbs = ({
"头部",	"颈部",	"胸口",	"后心","小腹",
});

mapping armor_vs_limb = ([
"头部" : ({ TYPE_HEAD }),
"颈部" : ({ TYPE_NECK }),
"胸口" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"后心" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"左肩" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"右肩" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"左臂" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"右臂" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT }),
"左手" : ({ TYPE_HANDS }),
"右手" : ({ TYPE_HANDS }),
"腰间" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT,TYPE_WAIST }),
"小腹" : ({ TYPE_CLOTH,TYPE_ARMOR,TYPE_SURCOAT,TYPE_WAIST }),
"左腿" : ({ TYPE_ARMOR }),
"右腿" : ({ TYPE_ARMOR }),
"左脚" : ({ TYPE_BOOTS }),
"右脚" : ({ TYPE_BOOTS }),
]);

//added by find. 每日 PK 超过三次官府开始对此人进行围剿.
//为避免 quit 逃避围剿,用 condition 方式.

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
                        sprintf("%s由于作恶多端，官府开始对%s进行围剿。", killer->name(1), 
                        gender_pronoun(killer->query("gender"))));
        }
}
//end.

string  *head_damage_me_msg = ({
	"你觉得头有一点发晕。\n",
	HIB "你觉得一阵晕眩，身体晃了一下。\n" NOR,
	BLU "你只得眼冒金星，浑身发飘。\n" NOR,
});

string *body_damage_me_msg = ({
	"你只觉$l隐隐作痛，体内真气受到一点振荡。\n",
	HIB "你只觉$l生疼，体内真气一阵乱窜。\n" NOR,
	BLU "你只觉得$l处剧痛，连带着体内真气一阵外泄。\n" NOR,
});

string *guard_msg = ({
        CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
        CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
        CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
        CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
        CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
        HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
        HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
        HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
        HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
        HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
        HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
        HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
       CYN "\n$N哈哈大笑，愉快地说道：承让了！\n\n" NOR,
       CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
       CYN "\n$N胜了这招，向后跃开三尺，叹道：真是拔剑四顾心茫然！\n\n" NOR,
       CYN "\n$n阁下确实了得，十年后在下一定前来领教！ \n\n" NOR,
       CYN "\n$n向后退了几步，说道：这场比试算我输了，下回看我怎么收拾你！\n\n" NOR,
       CYN "\n$n向后一纵，恨恨地说道：君子报仇，十年不晚！\n\n" NOR,

});

protected void create()
{
        seteuid(getuid());
        set("name", "战斗精灵");
        set("id", "combatd");
}

string damage_msg(int damage, string type)
{
        string str;
        if( damage == 0 ) return "结果没有造成任何伤害。\n";
        switch( type ) {
        case "□伤":
        case "割伤":
                if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l划出一道细长的血痕。\n";
                else if( damage < 40 ) return "结果「嗤」地一声划出一道伤口！\n";
                else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
                else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
                break;
       case "内伤":
	        if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
 	        else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
	        else if( damage < 40 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
	        else if( damage < 80 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
	        else if( damage < 120 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
	        else if( damage < 160 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
	        else if( damage < 240 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
	        else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
	        break;

        case "刺伤":
                if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
                else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
                else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
                else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
                else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉□糊的血窟窿！\n";
                else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
                break;
        
	case "瘀伤":
                if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
                else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
                else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
                else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
                else if( damage < 160 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
                else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
                else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
                break;
        
	case "抓伤":
                if( damage < 10 ) return "结果只是轻轻地抓到，比抓痒稍微重了点。\n";
                else if( damage < 20 ) return "结果在$p的$l抓出几条血痕。\n";
                else if( damage < 40 ) return "结果一抓命中，$n的$l被抓得鲜血飞溅！\n";
                else if( damage < 80 ) return "结果「嗤」地一声，$l被抓得深可见骨！！\n";
                else if( damage < 120 ) return "结果一抓命中，$n的$l被抓得血肉横飞！！！\n";
                else if( damage < 160 ) return "结果这一下「嗤」地一声抓得$n连晃好几下，差一点摔倒！\n";
                else if( damage < 240 ) return "结果$n哀号一声，$l被抓得筋断骨折！！\n";
                else return "结果只听见$n一声惨嚎，$l被抓出五个血窟窿！鲜血溅得满地！！\n";
                break;
        
	case "骨折":
                if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
                else if( damage < 20 ) return "结果在$n的身上造成一处轻伤。\n";
                else if( damage < 40 ) return "结果$n一支手被扭住，手臂登时造成一处扭伤！\n";
                else if( damage < 80 ) return "结果$n脉门被扣住，气息散乱，造成一处劲脉损伤！\n";
                else if( damage < 120 ) return "结果「啪」地一声，$n的双臂差点被折断！\n";
                else if( damage < 160 ) return "结果这一下「啪」一声，$n手臂折断，痛的身子震了一下！\n";
                else if( damage < 240 ) return "结果$n全身犹如散架，痛的几乎晕了过去！\n";
                else return "结果只听见$n惨叫一声，劲脉寸断！！\n";
                break;
        
	case "反弹伤":
                if( damage < 5 ) return "$N受到$n$z的反震，闷哼一声。\n";
                else if( damage < 10 ) return "$N被$n的$z震得气血翻腾，大惊失色。\n";
                else if( damage < 20 ) return "$N被$n的$z震得站立不稳，摇摇晃晃。\n";
                else if( damage < 40 ) return "$N被$n以$z反震，「嘿」地一声退了两步。\n";
                else if( damage < 80 ) return "$N被$n的$z反弹回来的力量震得半身发麻。\n";
                else if( damage < 120 ) return "$N被$n的$z反弹力一震，胸口有如受到一记重击，连退了五六步！\n";
                else if( damage < 160 ) return "$N被$n的$z一震，眼前一黑，身子向后飞出丈许！！\n";
                else return "$N被$n的$z一震，眼前一黑，狂吐鲜血，身子象断了线的风筝向后飞去！！\n";
                break;
        default:
                if( !type ) type = "伤害";
                if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
                else if( damage < 20 ) str = "结果造成轻微的";
                else if( damage < 30 ) str = "结果造成一处";
                else if( damage < 50 ) str = "结果造成一处严重";
                else if( damage < 80 ) str = "结果造成颇为严重的";
                else if( damage < 120 ) str = "结果造成相当严重的";
                else if( damage < 170 ) str = "结果造成十分严重的";
                else if( damage < 230 ) str = "结果造成极其严重的";
                else str =  "结果造成非常可怕的严重";
                return str + type + "！\n";
        }
}

string eff_status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
        if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
        if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
        if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
        if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
        if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
        if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
        if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
        if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
        return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
        if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
        if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
        if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
        if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
        if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
        if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
        return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
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
		return 0;  // 负重小于零时 power 永远等于零(by find.)

	if(userp(ob) && ob->is_ghost())
		return 0; // 鬼魂的攻防均为 0.

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
		/*若食物、饮水中有一项为 0，攻防减半。*/

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
		/*若食物、饮水中有一项为 0，攻防减半。*/

	if(ob->query_xuruo())
		rtn /= 2;
	if( (skill == "unarmed") && (ob->query_limb_wound("左手") || ob->query_limb_wound("左手")) )
		rtn /= 2;
	return rtn;
}

nomask int math_ap(object me) /* 计算ap */
{
	object weapon,second_weapon;
	int ap,aap,skill/*,second_skill*/;

	weapon = me->query_temp("weapon"); /* 右手兵器 */
	second_weapon = me->query_temp("secondary_weapon"); /* 左手兵器 */

	if(objectp(weapon))
	{
		ap = skill_power(me, weapon->query("skill_type"), SKILL_USAGE_ATTACK);
		/* 无论是右手兵器还是左右手兵器,只要拿在右手就算主兵器计算攻击力. */

		if(second_weapon) /* 如果双手都拿了兵器 */
		{
			if(weapon->query("skill_type") == second_weapon->query("skill_type"))
			/* 如果两手拿的兵器是同类兵器,判断此人此项武功的等级 */
			{
				skill = me->query_skill(weapon->query("skill_type"),1);
				if( skill >= 200)
					ap += ap/8;
				else if(skill > 100)
					ap += ap/10;
			}

			else /* 不同种类 */
			{
			aap = skill_power(me, second_weapon->query("skill_type"),
				SKILL_USAGE_ATTACK);
			ap = ap/100*80 + aap/100*35;
			/* 左手兵器的技能如果低于右手兵器的技能太多，
			   由于不能很好的配合，攻击力反而要降低。*/
			}
		}
	}

	else
	{
		if(objectp(second_weapon)) /* 如果只是左手拿兵器 */
			aap = skill_power(me, second_weapon->query("skill_type"),
				SKILL_USAGE_ATTACK);

		ap = skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
		if(aap)
			ap = ap/100*80 + aap/100*35;
			/* 左手兵器的技能如果低于右手空手的技能太多，
			   由于不能很好的配合，攻击力反而要降低。*/
	}

	if(me->is_busy()) ap /= 3;
	if(ap < 1) ap = 1;

	return ap;
}

nomask int math_dp(object me, object weapon) /* 计算dp */
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

int math_pp(object me) /* 计算pp */
{
	int pp;

	pp = skill_power(me, "parry", SKILL_USAGE_DEFENSE);

	// 这里是否由于胆识高而降低?
	pp -= pp*(me->query_cor())/1000;
	if(me->is_busy())
		pp /= 3;
	if(pp < 1)
		pp = 1;

	return pp;
}

protected mapping decide_action(object me,
	int flag /* flag = 1 指定左手 */
	) /* 选择此人的出招. */
{
	mapping act,l_act;

        act = me->query("actions"); /* 此人的右手 action */
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

	l_act = me->query("second_actions"); /* 此人的左手 action */
	if(!mapp(l_act) || !sizeof(l_act))
	{
		hand_flag = 0;
		return act;
	}

	if(flag) // 指定左手
	{
		hand_flag = 1;
		return l_act;
	}

	/* 什么因素决定此人用左手攻击还是用右手攻击? 目前没有,暂用随机数决定.*/
	if(random(100) < 55) /* 右手的可能性大一些.*/
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
 * 对方招式过来决定是招架还是躲闪.
 * 有影响的因素如下:
 * 1. 自己是否拿兵器? 拿兵器招架的可能性大.
 * 2. 对方是否拿兵器? 对方拿兵器躲闪的可能性大.
 * 3. dp 与 pp 的大小,
 *	dp > pp 躲闪可能性大.
 *	pp > dp 招架的可能性大.
 * 4. 自己同时有第一第二兵器招架可能性大.
 ***********************************************/
protected string
decide_attact_result(object me, object victim,int ap,int dp,int pp,int flag)
{
	int ratio = 50;	// + 招架的可能性大 - 躲闪的可能性大.
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

	if(!flag) // 替人挡招只能招架
	{
		if(hand_flag)
			weapon_me = me->query_temp("secondary_weapon");
		else
			weapon_me = me->query_temp("wepon");
	
		weapon_v  = victim->query_temp("weapon");
		if(!weapon_v)
			weapon_v = victim->query_temp("secondary_weapon");
	
		// 判断对于此招是躲闪还是招架.
		if(weapon_me)  // 进攻者有兵器?
		{
			ratio -= 5;
			if(weapon_me->query("falg") & EDGED) // 锋利的兵器
				ratio -= 5;
		}
	
		if(weapon_v)
		{
			ratio += 5;
			if(weapon_v->query("skill_type") == "throwing") // 暗器,以躲闪为主
				ratio -= 10;
			if(weapon_v->query("flag") & TWO_HANDED)
				ratio += 5;
			if(victim->query_temp("weapon")
			&& victim->query_temp("secondary_weapon") ) // 双手都有兵器,招架可能性大.
				ratio += 8; 
		}
	
		if( pp > dp ) // 招架技能高于躲闪技能
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
			return "parryd"; // 招架
	}

	else
	{
		if(random(ap + dp) < dp)
			return "dodged"; // 躲闪
	}

	return "attackd"; // 击中
}

protected void get_dodge_reward(object me,object victim)
{
	int exp_me,exp_v,gain,valve;

	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// 有任一方处于昏迷状态，没有任何奖励。
	if(userp(me) && userp(victim)) // user 对打。
		return;
	if(me->query("no_exp_gain"))	// 不允许的经验的 npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if( exp_v >= 2000 &&
	(exp_me <= exp_v/2
	// 对方比自己高太多躲开纯属误打误撞
	// 什么也得不到。
	|| exp_me >= exp_v*2))
		return;

	// 领悟力的阀值。
	valve = 12 + victim->query("age") - 16;
	if(valve < 12)
		valve = 12;
	if(valve > 32 )
		valve = 32;

	// gain 应该和攻击者的经验相关，
	// 攻击者的经验越高，躲闪者的由
	// 此而获得的战斗经验也应该越高
	// 反之越低。
	gain = random(give_exp(exp_me));
	if(gain < 1)
		gain = 1;

	// 战斗中能获得多少收获和一个人的
	// 领悟能力是息息相关的，这个阀值
	// 的计算加入了年龄的因素，从而避
	// 免了武功高了以后悟性在这里的作
	// 用越来越小直至可以忽略不记的情
	// 况。悟性的影响力在在每一个阶段
	// 都应当差不多平衡的。因为初入江
	// 湖虽说悟性低，但那时所需要领悟
	// 的武功也很浅显，以后悟性增加，
	// 但需要领悟的武功也越来越艰深。
	// 加入年龄还可以体现出生活中习武
	// 越早学的越快，等三、四十岁再开
	// 始练功难望大成的自然规律。
	// 这里取的是 query_int()，即此人
	// 装备的可增加悟性的宝物所提高的
	// 悟性部分也计算在内，体现出了宝
	// 物的作用，从而提高玩家在游戏中
	// 进行不断探索的动力，由于悟性所
	// 起作用的平衡性，宝物对于各个阶
	// 段的玩家都能体现出“宝物”的价
	// 值。这个阀值限定了最高值，不会
	// 出现七老八十没法练功的情况。
	if(random(victim->query_int()) >= valve)
	{
		victim->add("combat_exp",gain);
		victim->improve_skill("dodge", 1);
		if(random(100) < 50)
			me->add("potential",1);
	}

	// 当攻击者的经验高于躲闪者的经验时，
	// 躲闪者有机会获得一点对武功的领悟力。
	// 再次体现悟性。
	//if((exp_me >= exp_v) && (random(victim->query_int()) >= valve))
	//	victim->add("potential",1);
}

protected void get_parry_reward(object me,object victim)
{
	int exp_me,exp_v,gain,valve;
	
	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// 有任一方处于昏迷状态，没有任何奖励。
	if(userp(me) && userp(victim)) // user 对打。
		return;
	if(me->query("no_exp_gain"))	// 不允许的经验的 npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if( exp_v >= 2000 &&
	(exp_me <= exp_v/2
	|| exp_me >= exp_v*2))
		return;

	// 领悟力的阀值。
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

	// 只有在对方经验大于自己的时候。
	//if((exp_me > exp_v) && (random(victim->query_int()) >= valve))
	//	victim->add("potential",1);
}

protected void get_attack_reward(object me,object victim,string attack_skill)
{
	int exp_me,exp_v,gain,valve;
	
	if(!me || !victim)
		return;
	if(!living(me) || !living(victim))
		return;		// 有任一方处于昏迷状态，没有任何奖励。
	if(userp(me) && userp(victim)) // user 对打。
		return;
	if(victim->query("no_exp_gain")) // 不允许的经验的 npc
		return;

	exp_me = me->query("combat_exp");
	exp_v = victim->query("combat_exp");

	if(exp_me != 0 && exp_v <= exp_me/2)
/*
	|| exp_v >= exp_me*2)
*/
		return;

	// 领悟力的阀值。
	valve = 12 + victim->query("age") - 16;
	if(valve < 12)
		valve = 12;
	if(valve > 32 )
		valve = 32;

	// 此处gain 应该和被打击者的经验相关，
	// 被打击者的经验越高，击中此人而获得
	// 的战斗经验也应该越高，反之越低。
	gain = random(give_exp(exp_v));
	if(gain < 1)
		gain = 1;
	if(random(victim->query_int()) >= valve)
	{
		me->add("combat_exp",gain);
		// 有 80% 可能性获得潜能。
		//if(random(100) < 80)
		//	me->add("potential",1);
	}
	else
		me->add("combat_exp",1);
	// 此处武功无条件提升。
	me->improve_skill(attack_skill, 1);

	// 有 80% 可能性获得潜能。
	if(random(100) < 80)
		me->add("potential",1);
}

protected int count_armor_protect(object me,object armor,int factor,object weapon,int w_damage)
{
	int ret,fth,mangle,dd;
	string skill;

	// 兵器有透甲能力。如透甲锥之类的暗器
	if(objectp(weapon) && weapon->through_armor())
		return 0;

	// 护甲损坏程度
	mangle = armor->query("armor_mangle");
	if(mangle >= A_MAX_MANGLE)
		return 0;
	ret = armor->query("armor_prop/armor");

	// 不受损的护具，如帮会信物等。
	if(armor->cant_be_damage())
		return 1;

	if(mangle)
		ret = ret*(((A_MAX_MANGLE-mangle)*100)/A_MAX_MANGLE)/100;
	if(ret <= 0)
		return 0;

	// 内功是否有穿透护甲的能力
	// 如借物传力、隔山打牛之类
	// 徒手此能力才起作用
	if(!weapon)	// 徒手
	{
		if(factor > 0 && (skill = SKILL_D(me->query_skill_mapped("force"))))
		{
			fth = skill->query_through_armor(me,factor);
			if(fth >= ret)	// 穿透力大于防护力
				ret = 0;
			else
				ret -= fth;
		}
		armor->set("armor_mangle",++mangle>A_MAX_MANGLE?A_MAX_MANGLE:mangle);
		return ret;
	}

	// 有兵器护甲起作用，但要受损坏
	if(w_damage <= 0)
		return ret;	// 兵器没有杀伤力，不会损坏护甲

	// 兵器对护甲的伤害
	dd = (WEAPON_D->query_rigidity(weapon) - WEAPON_D->query_rigidity(armor))/10;
	if(dd < 1)
		dd = 1;

	armor->set("armor_mangle",(dd + mangle)>A_MAX_MANGLE?A_MAX_MANGLE:(dd + mangle));
	return ret;
}

// 打击别人的力度和被打击人所受的伤害程度应该与此人的当时身体状态有关。
nomask varargs int
do_attack(object me,		/* 进攻者*/
	  object victim,	/* 防御者*/
	  int attack_type,	/* 攻击种类*/
	  int flag		/* 指定左手标记 */
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

#ifdef WIZARD_FLAG	/* 巫师与玩家不能发生战斗. */
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

	// 如果双方没有处于战斗状态,可以发出特攻以后立刻
	// surrender,这时会解除战斗状态,对方不会攻击自己,
	// 可是发出的特攻不会停止,依然会向对方攻击.
	// 此判断只为避免这种投机取巧的情况.
	// 这也会造成一些问题,例如 entrap 之类在正常状态下
	// 突然发招直接调用 attack 函数的情况,遇这类情况要
	// 先用 me->fight_ob(ob) 使双方进入战斗状态再发招,
	// 如有必要在发招后用 me->remove_enemy(ob) 解除战斗状态.
	if(!me->is_fighting(victim) && !victim->is_fighting(me))
		return 0;

	weapon = me->query_temp("weapon");
	second_weapon = me->query_temp("secondary_weapon");

	// 判断 attacker 的 action.
	action = decide_action(me,flag);
	if(!action) return 0;

	if(hand_flag)	/* 调整'当前兵器' weapon。*/
		weapon = second_weapon;

	if( !me->query("env/mute")
	&& (!victim->query("env/mute")
	|| (userp(me)
	&& userp(victim))) )
		mute_flag = 0;

	if(!mute_flag)
        	result = sprintf("\n%s！\n",action["action"]);

	if(objectp(weapon))
		attack_skill = weapon->query("skill_type");
	else
		attack_skill = "unarmed";

	// 判断攻击部位

	/* 此设置可以使一些武功选择使用此武功的人的攻击部位。
	 * 可以产生例如地趟刀法专攻下三路的效果。
	 * 不过增加不少系统开销，好在现在机器越来越快。
	 */
	if(martial_skill = me->query_skill_mapped(attack_skill))
		limb = SKILL_D(martial_skill)->query_attack_limb(me,victim);

	if(!limb)
	{
		limbs = victim->query("limbs");
		if(!limbs || !arrayp(limbs))
		{
			message_vision("COMBAT_D: $N决定部位错误。\n",victim);
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
		|| (vdb["sen"] < vdb["max_sen"]*2/5))  // 不行了，抗不住了
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
					              result = replace_string( result, "$w", "手指" );

				message_vision(result, me, victim);
				message_vision(HIC BWHT"$N飞身移步，挡在了$n的身前。\n"NOR,ob,victim);
				result = "";
			}

			victim = ob;
			array_flag = 1;
			attack_type = TYPE_QUICK;
		}
	}

	// 计算 ap、dp、pp.
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

	if(member_array(limb,danger_limbs) != -1) /* 向危险部位发动进攻 */
	{
		ap -= ap/10;	/* 击中的可能性减小10% */
		if(ap <1)
			ap = 1;
	}

	// 计算战斗结果。
	res = decide_attact_result(me, victim, ap, dp, pp, array_flag);

	switch(res)
	{
	case "guarded":
		if(!result)
			result = HIC"$n身边映出一道蓝色的光环，将$N的招式挡在了外面\n"NOR;
		else
			result += HIC"$n身边映出一道蓝色的光环，将$N的招式挡在了外面\n"NOR;
		break;

	case "dodged":	// 躲闪
		defense_skill = victim->query_skill_mapped("dodge");
		if(!defense_skill)
			defense_skill = "dodge";
		if(!mute_flag)
			result += SKILL_D(defense_skill)->query_dodge_msg();
		break;

        case "parryd": // 招架
		defense_skill = victim->query_skill_mapped("parry");
		if(defense_skill)  /* 调整拿武器时的 parry 显示信息。*/
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

	case "attackd": // 击中

		/* 兵器的伤害力取随机值。(有轻有重、有深有浅)*/
		/* 兵器损坏度起作用. 只有当前兵器的杀伤力起作用 */

		if(me->query("race") == "野兽")	// 野兽的 damage 是直接上 apply 的
		{
			damage = me->query_temp("apply/damage");
			damage = damage/3 + random(to_int(damage/3*2));
			if(damage < 1)
				damage = 1;
		}

		else if(weapon)
		{
			w_damage = weapon->query("weapon_prop/damage");

			// 如果兵器受了损伤
			if(mangle = weapon->query("weapon_mangle"))
				damage = w_damage*( (W_MAX_MANGLE - mangle)*100/W_MAX_MANGLE )/100;
			else
				damage = w_damage;
			damage = damage/3 + random(to_int(damage/3*2));

			// 有兵器就至少有 1 点伤害
			if(damage < 1)
				damage = 1;
		}

		/* 招式的伤害力 */
		if(damage)
		{
			if(action["damage"])
				damage += action["damage"] * damage / 1000;

			// 胆识高勇于进攻疏于防守，击中会造成更大的伤害。
			damage += damage*(me->query_cor())/1000;
		}

		wound = me->query_str();
		factor = me->query("force_factor");
		factor = (force = me->query("force"))>=factor?factor:force;

		// 内功引起的伤害。
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

		// 经验对伤害的影响
		exp = victim->query("combat_exp");
		if((exp+random(exp))/2 > me->query("combat_exp")) 
			damage -= damage / 4;

		// 硬功的防护作用。
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

		/* armor 起作用。*/

		if(victim->query("race") == "野兽")	// 野兽的 armor 是直接上 apply 的
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

		// 作用伤害

		if( damage <= 0 )
		{
			if(!mute_flag)
				result += CYN"结果竟然没有造成任何伤害!\n"NOR;
		}
		else
		{
			victim->receive_damage("kee", damage, me );
			/* 有兵器并且兵器有杀伤力，致伤附带1/4的上限伤 */
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
			              result = replace_string( result, "$w", "手指" );
		message_vision(result, me, victim);
	}

	/* 双方都有兵器，如果招架开意味着双方兵器相交 。*/
	if( res == "parryd"
	&& weapon_v
	//&& weapon_v->query("skill_type") != "throwing"
	// 暗器不能招架
	&& weapon )
	{
		w_action = weapon->query("actions");
		verbs = weapon->query("verbs");
		// 暗器不作此判断
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
				"AP：%d，DP：%d，PP：%d，伤害力：%d\n" NOR,
                                ap/100, dp/100, pp/100, damage));
                else
                        tell_object(me, sprintf(GRN 
				"AP：%d，DP：%d，PP：%d\n" NOR,
                                ap/100, dp/100, pp/100));
        }
	if(wizardp(victim) && (string)victim->query("env/combat")=="verbose")
	{
                if( damage > 0 )
                        tell_object(victim, sprintf(GRN 
				"AP：%d，DP：%d，PP：%d，伤害力：%d，护甲作用：%d\n" NOR,
                                ap/100, dp/100, pp/100, damage,armor));
                else
                        tell_object(victim, sprintf(GRN 
				"AP：%d，DP：%d，PP：%d\n" NOR,
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
        if(functionp(action["post_action"])  // 此地方只用来控制暗器
	&& weapon
	&& arrayp(verbs = weapon->query("verbs"))
	&& member_array( "throw" ,verbs) != -1)
		evaluate( action["post_action"], me, victim, weapon, damage);
*/

	// 某些部位的特殊伤害：
	if(res == "attackd" && damage)
	{
		switch(limb)
		{
			// 头、颈受伤会伤一些神。
			case "头部":
			case "颈部":
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
			// 击中这些部位真气会受到振荡。
			case "胸口":
			case "后心":
			case "小腹":
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
			// dodge 奖励
			get_dodge_reward(me,victim);
			break;
	        case "parryd": // 招架
			// parry 奖励
			get_parry_reward(me,victim);
			break;
		case "attackd": // 击中
			get_attack_reward(me,victim,attack_skill);
			break;
	}

        // 是否进行反击
        if( attack_type==TYPE_REGULAR	// 正常进攻
	&& damage < 1			// 没有受到伤害
	&& victim->query_temp("is_guarding"))
	{
		victim->set_temp("is_guarding", 0);

		if(!victim->is_busy()		// 没有在 busy
		&& victim->query("kee")*100/victim->query("max_kee") >= 40
		&& random(victim->query_cor()) > (me->query_cor()/2))
                {
			if( !me->query("env/mute")
			&& !victim->query("env/mute")
			||(userp(me)&&userp(victim)))
				message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
			do_attack(victim, me, TYPE_RIPOSTE);
		}
	}

        if( attack_type==TYPE_REGULAR	// 正常进攻
	&& damage > 1			// 受到伤害
	&& random(me->query("kar")+victim->query("kar")) < me->query("kar")
	&& random(20) <= 10)
	{
		message_vision("\n$N一击得手，乘胜追击继续进攻。\n",me);
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
	note["title"] =CYN+  local[5] + "年" + month + "月" + local[3]
			+ "日" + local[2] + "时" + local[1] + "分           "+NOR;
	note["author"] =YEL+ env->query("short")+NOR;
	note["time"] = time();
	text =ob1->short()+ RED"\n\t胜\n"NOR + ob2->short();
	bbs->done_post(ob1, note, text);
	write("留言完毕\n");
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
		message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);
	}

	// NPC
	if(!userp(obj)
	&& (obj->query(NO_KILL)
	|| obj->is_master()) )
		return;

	call_other(__FILE__, "start_" + type, me, obj );
}

// 杀气
protected void start_berserk(object me, object obj)
{
	int bellicosity;

        bellicosity = (int)me->query("bellicosity");

	if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 )
		return;

	me->delete_temp("looking_trouble");
	if(me->query("can_speak"))
		message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
			+ "看你实在很不顺眼，去死吧。\n", me, obj);
	me->kill_ob(obj);
	obj->kill_ob(me);
	if(userp(me) && userp(obj))
		obj->accept_first_kill(me);
}

// 结仇
protected void start_hatred(object me, object obj)
{
	if(me->query("can_speak"))
		message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
        me->kill_ob(obj);
	obj->kill_ob(me);
}

// 杀官
protected void start_vendetta(object me, object obj)
{
        me->kill_ob(obj);
}

// 自动杀人
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
                        message_vision("\n$N死了。\n\n", ob);
                        break;
                case "unconcious":
                        message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
                        break;
                case "revive":
                        message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
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
	if(exp < 10000)		// 利于新手练功.
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

		tell_object(memb[i],sprintf("你所在的队伍杀死%s，你分到%d点经验。\n\n",name,e));
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

		tell_object(memb[i],sprintf("『%s』杀死%s，你分到%d点经验。\n\n",
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
					sprintf("%s在比武中被%s杀死了。", victim->name(1), 
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
							sprintf("%s被『仁义庄』除掉了。",
								victim->name(1)));
						news = sprintf("%s(%s)『仁义庄』除掉了！！\n",
							victim->name(1));
						break;
					}
				}

				if(!pass)
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s被%s带领的『%s』杀死了。",
							victim->name(1),
							killer->query_array_master()->name(1),
							killer->query_array_name()));
					news = sprintf("%s(%s)被%s(%s)带领的『%s』做掉啦！！\n",
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
							sprintf("%s被『仁义庄』除掉了。",
								victim->name(1)));
						news = sprintf("%s(%s)『仁义庄』除掉了！！\n",
							victim->name(1));
						break;
					}
				}

				if(!pass)
				{
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s被%s带领的队伍杀死了。",
							victim->name(1),
							killer->query_team_leader()->name(1)));
					news = sprintf("%s(%s)被%s(%s)带领的队伍做掉啦！！\n",
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
							sprintf("%s被『仁义庄』除掉了。", victim->name(1)));
						news = sprintf("%s(%s) 被『仁义庄』除掉了！！\n",
							victim->name(1),capitalize(victim->query("id")) );
					}
					else
					{
						news = sprintf("%s(%s) 被 %s(%s) 做掉啦！！\n",
							victim->name(1),capitalize(victim->query("id")),
							killer->name(1),
							capitalize(killer->query("id")) );
						if(valid)
							victim->set("my_killer", geteuid(killer));
					}
				}

				if(!pass)
					CHANNEL_D->do_channel(this_object(), "rumor",
						sprintf("%s被%s杀死了。", victim->name(1), killer->name(1)));
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
					sprintf("%s身上的伤口血流不止而亡。", victim->name()));
				break;
			case "poison":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s毒发身亡了。", victim->name()));
/*
				news = sprintf("%s(%s)中毒医治不及，毒发身亡了！！\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "illness":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s重病不治而死。", victim->name()));
/*
				news = sprintf("%s(%s)重病不治而死！！\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "tire":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s体力消耗过度，累死了。", victim->name()));
/*
				news = sprintf("%s(%s)体力消耗过度，活活累死了！！\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "hunger":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s没吃没喝，饥寒交迫而死。", victim->name()));
/*
				news = sprintf("%s(%s)没吃没喝，饥寒交迫而死！！\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			case "trip":
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s被活活摔死了。", victim->name()));
/*
				news = sprintf("%s(%s)被活活摔死了！！\n",
					victim->name(),capitalize(victim->query("id")));
*/
				break;
			default:
				CHANNEL_D->do_channel(this_object(), "rumor",
					sprintf("%s莫名其妙的死了。", victim->name()));
/*
				news = sprintf("%s(%s)一个没注意，莫名其妙的离开了人世！！\n",
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
	/* 杀死了 doctor,会有72小时得不到医治. 见 DOCTOR 物件.*/

	/* 此处为防止一个人把他打晕让另一个人杀死 这种取巧方法. */
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
			&& quest["quest"] == "杀"
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
					tell_object(killer,sprintf("你杀死%s得到了%s点实战经验。\n\n",
						victim->name(),chinese_number(gain)));
					killer->add("combat_exp",gain);
					//killer->save();
				}
			}

			// gongji 功绩
			if( killer->query("class")
			&& killer->query("class") == victim->query("class"))
			{
				if(userp(victim))
				{
					killer->add("family/gongji",-500);
					tell_object(killer,sprintf("由于你残害同门弟子，师门功绩下降 %d 点。\n",500));
				}
				else
				{
					if(killer->is_apprentice_of(victim))
					{
						killer->add("family/gongji",-1000);
						tell_object(killer,sprintf("由于欺师灭组的行为，师门功绩下降 %d 点。\n",1000));
					}
					else if( killer->query("family/generation") >
					victim->query("family/generation") )
					{
						killer->add("family/gongji",-600);
						tell_object(killer,sprintf("由于你残害同门尊长，师门功绩下降 %d 点。\n",600));
					}
					else
					{
						killer->add("family/gongji",-300);
						tell_object(killer,sprintf("由于你残害同门，师门功绩下降 %d 点。\n",300));
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

		log_file("player_die",sprintf("%s(%s) 于 %s 被 %s%s 杀死了。\n",
			user->name(1),user->query("id"),ctime(time()),
			(userp(ob))?ob->name(1):"NPC",
			(userp(ob))?"("+ob->query("id")+")":""));
	}

	else
	{
		switch(ob)
		{
			case "poison":
				reason = "毒发身亡";
				break;
			case "illness":
				reason="重病不治而死";
				break;
			case "tire":
				reason="体力消耗过度，累死了";
				break;
			case "hunger":
				reason="没吃没喝，饥寒交迫而死";
				break;
			case "trip":
				reason="被活活摔死了";
				break;
			default:
				reason="莫名其妙的死了";
		}
		log_file("player_die",sprintf("%s(%s) 于 %s %s。\n",
			user->name(1),user->query("id"),ctime(time()),reason));
	}

	log_file("player_die",sprintf("\tlost exp: %d, potential: %d.\n",exp,pot/2));
}
