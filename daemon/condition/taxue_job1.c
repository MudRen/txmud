// taxue_job1.c

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
              me->clear_condition("taxue_job1");
                }
        if (!duration) return 0;
        me->apply_condition("taxue_job1", duration - 1);
        return 1;
}

