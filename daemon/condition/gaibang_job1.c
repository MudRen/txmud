// taxue_job.c
// by dicky

#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
              me->clear_condition("gaibang_job1");
                  }
        if (!duration) return 0;
        me->apply_condition("gaibang_job1", duration - 1);
        return 1;
}