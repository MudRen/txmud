// po.c
// 「破」字诀
// 独孤剑法(dugu-sword)的特攻   破天下兵器
// by dicky.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int skill,damage;

//        target = me->select_opponent();

        skill = me->query_skill("dugu-sword",1);

	if( !target ) target = offensive_target(me);

        if( !target  || !target->is_character() || !me->is_fighting())
                return notify_fail("『独孤剑法』的「破」字诀只能对战斗中的对手使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方没有使用兵器，你无法使用「破」字诀。\n");

        if( skill < 120)
                return notify_fail("你的独孤九剑等级不够, 不能使用「破」字诀！\n");

        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「破」字诀！\n");
 
        msg = HIC "\n$N一声断喝，使出独孤九剑的「破」字诀逼近$n，手中"+weapon->name()+HIC "幻出重重剑影，如柔丝般向$n裹去。\n\n";
        message_vision(msg, me, target);
 
        damage = random(skill);

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
        {
                if(userp(me))
                        me->add("force",-300);
                msg = "$n顿时觉得压力骤增，手腕一麻，手中";
                msg += weapon2->name();
                msg += "脱手而出！\n\n" NOR;

                target->receive_damage("kee", damage);
                target->start_busy(1);
                weapon2->move(environment(me));
        }
        else
        {
                if(userp(me))
                        me->add("force",-300);
                msg = "可是$n看破了$N的剑路，立刻采取守势，使$N的「破」字诀没有起到任何作用。\n"NOR;
                me->start_busy(1);
        }
        message_vision(msg, me, target);
	me->start_perform_busy(8);
        return 1;
}

