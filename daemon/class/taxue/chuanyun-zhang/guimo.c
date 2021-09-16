// chuanyun.c
// by dicky

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
      if( !target ) target = offensive_target(me);
     
      if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
      return notify_fail("「神出鬼没」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手使用「神出鬼没」！\n");
      
      if( (int)me->query_skill("chuanyun-zhang",1) < 120 )
      return notify_fail("你的穿云催魂掌不够娴熟，不会使用「神出鬼没」！\n");
      
      if(userp(me) && (int)me->query_skill("taxue-force",1) < 100 )
      return notify_fail("你的踏雪神功等级不够，不能使用「神出鬼没」！\n");  
      
      if(userp(me) && ! me->query_skill("taxue-force"))
      if(userp(me) && me->query_skill_mapped("force") != "taxue-force")
      return notify_fail("你没有踏雪神功内功，无法使用「神出鬼没」进行攻击。\n"); 
    
      if( (int)me->query_con() < 25 )
      return notify_fail("你的身体不够强壮，不能使用「神出鬼没」！\n");
      
      if( (int)me->query("max_force") < 800 )
      return notify_fail("你的内力太弱，不能使用「神出鬼没」！\n");
      
      if( (int)me->query("force") < 600 )
         return notify_fail("你的内力太少了，无法使用出「神出鬼没」！\n");   
                                                                                 
      if (me->query_skill_mapped("unarmed") != "chuanyun-zhang")
                return notify_fail("你现在无法使用「神出鬼没」进行攻击。\n");                                                       
      if(target->query_temp("guimo"))
          return notify_fail("对方已经身受「神出鬼没」，你不用费劲了！\n");
      
      message_vision(HIR"\n突然$N眼射精光，双手合十互击，陡然向外一分，双掌顿时变得轻\n灵飘逸，灵动异常，霎时幻起漫天的掌影向$n盖了过去！\n\n"NOR,me, target);
     if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 ||
         random((int)me->query_skill("force")) > (int)target->query_skill("force")/2){         
            me->add("force", -400);
            me->add("gin", -50);
            me->start_busy(1);
            target->start_busy(1);
            if(me->query("force")*2 < target->query("force"))  
                 tell_object(me, HIW"你只觉"+target->name()+"体内内力极强，你暗藏在掌内的各种力道根本送不出去！\n"NOR);
            else{
                 tell_object(me, HIR"在刚一触到"+target->name()+"的身体时，你便暗暗发力，将隐藏在在蕴涵在掌内的力道送了过去！\n"NOR);
                 tell_object(target, HIR"你一晃眼，只见"+me->name()+"漫天的掌影向已经打在你的身上，跟着几股说不出的暗劲顺势传了过来！\n"NOR);
                 target->set_temp("guimo", 1);
                 target->add_temp("apply/dexerity", -(target->query("dex", 1)/2));  
                 target->add_temp("apply/intelligence", -(target->query("int", 1)/2));    
                 target->add_temp("apply/constitution", -(target->query("con", 1)/2));  
                 target->apply_condition("guimo_poison", 10+target->query_condition("guimo_poison"));
                 target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), me->query_skill("force")/2); 
                }
            target->receive_damage("kee", (int)me->query_skill("force")*2); 
	    target->receive_damage("gin", (int)me->query_skill("force")/3);
            me->start_perform_busy(8); 
            } 
            else 
               {       
                me->start_busy(1);
                me->add("force", -(100+random(100))); 
                me->add("gin", -80);             
                message_vision(MAG"只见$n轻轻一转身，已经绕到了$N身后。而$N却因劲力打空不受控制，头脑眩晕！\n\n"NOR, me, target);
               }
           me->start_perform_busy(8); 
           return 1;
}

void remove_effect(object target)
{
      if(!target) return;  
      target->add_temp("apply/dexerity", target->query("dex", 1)/2);  
      target->add_temp("apply/intelligence", target->query("int", 1)/2);    
      target->add_temp("apply/constitution", target->query("con", 1)/2);   
      target->delete_temp("guimo");
      tell_object(target, HIW"终于，体内那几股暗劲在遍布你的全身后开始慢慢散去了。\n"NOR);
}
