// heiyi_task.c
// by dicky

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {  
           tell_object(me, HIR"����˵������֧�������ڶ�Ҫ�����ˣ�\n"NOR);                
           return 0;
        }
        me->apply_condition("heiyi_task", duration - 1);
        return 1;
}