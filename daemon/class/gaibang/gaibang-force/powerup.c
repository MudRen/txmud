// powerup.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        //effect = 8 + 100/15;
        if( target != me ) return notify_fail("��ֻ����ؤ���ķ������Լ���ս������\n");
        if( (int)me->query("force") < 100 )  return notify_fail("�������������\n");
        //if( (int)me->query("gaibang-force") < 60 )  return notify_fail("���ؤ���ķ���Ϊ������\n");
        if( (int)me->query_temp("powerup") ) return notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("force");
        me->add("bellicosity", 100 + skill/2 );
        me->add("force", -100);
        me->receive_damage("kee", 0);
        message_vision(
        HIB"$N������һ�������������Ե���ֱ��ʮ���ع���ȫ��һ�������\n" NOR, me);
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
        tell_object(me, "�����������������ϣ��������ջص��\n");
}
