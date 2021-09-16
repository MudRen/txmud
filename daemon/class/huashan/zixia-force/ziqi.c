// ziqi.c
// 紫气东来,『紫霞神功』的特攻

#include <ansi.h>

int exert(object me, object target)
{
	int s = me->query_skill("zixia-force",1), effect, last;

	if(!me->query("family/master_yue_teach"))
		return 0;

	if(me->query_temp("apply/huashan-sword"))
		return notify_fail("你正在施展『紫气东来』，不能再行功了。\n");

	if(me->query("force") < 150)
		return notify_fail("你的内力不够，无法施展『紫气东来』。\n");

	if(s < 100)
		return notify_fail("你的『紫霞神功』等级不够，无法施展『紫气东来』\n");

	effect = 8 + 100/15;

	last = 120 + effect*5;

	message_vision(HIY"\n$N暗催内力，提丹田气直上十二重楼。脸上紫气隐隐一现，随即消失...\n\n"NOR,me);
	me->set_temp("apply/huashan-sword",effect);
	me->add("force",-150);
	me->start_perform_busy(8);
	call_out("stop_up",last,me);
	return 1;
}

protected void stop_up(object who)
{
	if(!who)
		return;

	if(who->query_temp("apply/huashan-sword"))
	{
		who->delete_temp("apply/huashan-sword");
		tell_object(who,"\n你觉得内功一泄，『紫气东来』效用消失了。\n\n");
	}
}
