#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      me->receive_wound("kee", random(100));
      
      switch(random(5)){
      case 0 : 
              msg = HIR"$N突然脚下一慢，好象大腿的穴道被封住了！\n"NOR;
              me->start_busy(3+random(3));
              break;
      case 1 : 
              msg = HIR"$N突然眉头一皱，好象是受了内伤！\n"NOR;
              me->receive_damage("kee", 300+random(200));
              me->receive_wound("kee", 200);
              me->start_busy(2);
              break;
      case 2 : 
              msg = HIR"$N的身子突然晃了两晃，好象是中了阴毒的内伤！\n"NOR;
              me->add("force", -300+random(200));
              me->start_busy(2);
              break;
      case 3 : 
              msg = HIR"$N突然脚下一晃，好象是受了暗伤！\n"NOR;
              me->receive_damage("gin", 40);
              me->receive_wound("gin", 20);
              me->start_busy(2);
              break;
      case 4 : 
              msg = HIR"$N脚下恍惚，精神不能集中，好象是中了内伤！\n"NOR;
              me->add("force", -250+random(200));
              me->start_busy(2);
              break;
      }
      message_vision(msg, me);
      me->apply_condition("guimo_poison", duration - 1);
      if( duration < 1 ) return 0;
      return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
