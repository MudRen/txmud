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
                return notify_fail("你现在忙得很！！\n");
        extra = me->query_skill("qiuyue-fork",1);
        if ( extra < 50) return notify_fail("你的秋月枪法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIB"横扫千军"NOR+"只能对战斗中的对手使用。\n");
        if (me->query("force")<=100) return notify_fail("你的内力不足，无法使用"+HIB"横扫千军"NOR+"\n");
        map = me->query_skill_map();
        if( undefinedp(map["fork"]) ) 
                return notify_fail("你没有enable枪法\n");
        if( map["fork"] != "qiuyue-fork" )
                return notify_fail("你并没有使用秋月枪法\n"); 
        weapon = me->query_temp("weapon");      
        if( !objectp(weapon) || weapon->query("skill_type")!= "fork" )
                return notify_fail("你并没有使用枪\n");
        me->add("force",-100);
        message_vision("$N使出秋月枪法之不传之秘「"+HIB"横扫千军"NOR+"」\n",me);
        me->start_busy(2);
      //  if (random(me->query("combat_exp")*(extra/30+1))>target->query("combat_exp"))
      //  {
          weapon = me->query_temp("weapon");
          message_vision(HIY "$N大吼一声，双膀一较力，手中一个枪决使出，连刺数枪！\n" NOR,me,target);
          message_vision(HIY "上一枪......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);  
          message_vision(HIY "下一枪......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);  
          message_vision(HIY "左一枪......\n" NOR,me,target);
          COMBAT_D->do_attack(me,target);
          message_vision(HIY "右一枪......\n" NOR,me,target);  
          COMBAT_D->do_attack(me,target);
          message_vision(HIY "中间再来一枪......\n" NOR,me,target);
            COMBAT_D->do_attack(me,target);
  //        message_vision(HIY "$N一连递出了四招,$n被攻击的手忙脚乱！\n" NOR,me,target);

        //  target->receive_damage("kee",0,me);
        //  target->start_busy(1);
       // }
       // else
       // {
       //   message_vision("但$n看破$N的意图，趁势发动攻击！\n",me,target);
       //   weapon = target->query_temp("weapon");
       //   COMBAT_D->do_attack(target,me,weapon);
       // }
        return 1;
}
