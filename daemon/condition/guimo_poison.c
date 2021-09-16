#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    string msg;
      me->receive_wound("kee", random(100));
      
      switch(random(5)){
      case 0 : 
              msg = HIR"$NͻȻ����һ����������ȵ�Ѩ������ס�ˣ�\n"NOR;
              me->start_busy(3+random(3));
              break;
      case 1 : 
              msg = HIR"$NͻȻüͷһ�壬�������������ˣ�\n"NOR;
              me->receive_damage("kee", 300+random(200));
              me->receive_wound("kee", 200);
              me->start_busy(2);
              break;
      case 2 : 
              msg = HIR"$N������ͻȻ�������Σ��������������������ˣ�\n"NOR;
              me->add("force", -300+random(200));
              me->start_busy(2);
              break;
      case 3 : 
              msg = HIR"$NͻȻ����һ�Σ����������˰��ˣ�\n"NOR;
              me->receive_damage("gin", 40);
              me->receive_wound("gin", 20);
              me->start_busy(2);
              break;
      case 4 : 
              msg = HIR"$N���»�㱣������ܼ��У��������������ˣ�\n"NOR;
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
