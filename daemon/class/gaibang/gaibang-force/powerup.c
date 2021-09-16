// powerup.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        //effect = 8 + 100/15;
        if( target != me ) return notify_fail("你只能用丐帮心法提升自己的战斗力。\n");
        if( (int)me->query("force") < 100 )  return notify_fail("你的内力不够。\n");
        //if( (int)me->query("gaibang-force") < 60 )  return notify_fail("你的丐帮心法修为不够。\n");
        if( (int)me->query_temp("powerup") ) return notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("force");
        me->add("bellicosity", 100 + skill/2 );
        me->add("force", -100);
        me->receive_damage("kee", 0);
        message_vision(
        HIB"$N深吸了一口气，提内力自丹田直上十二重宫，全身一阵颤栗！\n" NOR, me);
        me->add_temp("apply/attack", skill/6);
        me->add_temp("apply/dodge", skill/6);
       // me->set_temp("apply/taizu-changquan",effect);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}
void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的提升攻击运行完毕，将内力收回丹田。\n");
}
