// heng.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
static object *enemy = ({});
int perform(object me, object target)
{
        int extra;
        mapping map;
        object weapon;
        if(me->is_busy())
                return notify_fail("������æ�úܣ���\n");
        extra = me->query_skill("qiuyue-fork",1);
        if ( extra < 50) return notify_fail("�������ǹ�����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIB"��ɨǧ��"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query("force")<=100) return notify_fail("����������㣬�޷�ʹ��"+HIB"��ɨǧ��"NOR+"\n");
        map = me->query_skill_map();
        if( undefinedp(map["fork"]) ) 
                return notify_fail("��û��enableǹ��\n");
        if( map["fork"] != "qiuyue-fork" )
                return notify_fail("�㲢û��ʹ������ǹ��\n"); 
        weapon = me->query_temp("weapon");      
        if( !objectp(weapon) || weapon->query("skill_type")!= "fork" )
                return notify_fail("�㲢û��ʹ��ǹ\n");
        me->add("force",-100);
        message_vision("$Nʹ������ǹ��֮����֮�ء�"+HIB"��ɨǧ��"NOR+"��\n",me);
        me->start_busy(2);
      //  if (random(me->query("combat_exp")*(extra/30+1))>target->query("combat_exp"))
      //  {
          weapon = me->query_temp("weapon");
          message_vision(HIY "$N���һ����˫��һ����������һ��ǹ��ʹ����������ǹ��\n" NOR,me,target);
          message_vision(HIY "��һǹ......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);  
          message_vision(HIY "��һǹ......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);  
          message_vision(HIY "��һǹ......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);
          message_vision(HIY "��һǹ......\n" NOR,me,target);  
          COMBAT_D->do_attack(me,target);
          message_vision(HIY "�м�����һǹ......\n" NOR,me,target);
            COMBAT_D->do_attack(me,target);
  //        message_vision(HIY "$Nһ���ݳ�������,$n����������æ���ң�\n" NOR,me,target);

        //  target->receive_damage("kee",0,me);
        //  target->start_busy(1);
       // }
       // else
       // {
       //   message_vision("��$n����$N����ͼ�����Ʒ���������\n",me,target);
       //   weapon = target->query_temp("weapon");
       //   COMBAT_D->do_attack(target,me,weapon);
       // }
        return 1;
}
