// heal.c
// 可为战斗中人疗伤，但效果减半。

#define SKILL_FORCE	"suiyu-force"

int exert(object me, object target)
{
	int eff,max,busy;

	if( me->is_fighting() )
		return notify_fail("战斗中无法行功疗伤？\n");

	if( (me->query("max_force") < 500)
	|| (me->query_skill(SKILL_FORCE,1) < 150) )
		return notify_fail("你的内功修为不够，无法行功疗伤。\n");

	if( me->query("force") < 100 )
		return notify_fail("你的真气不够，无法行功疗伤。\n");

	if( (eff=me->query("eff_kee")) < (max=me->query("max_kee")) / 3 )
		return notify_fail("你已经受伤过重，现在提气行功只怕有生命危险！\n");

	if((target==me?eff:target->query("eff_kee")) >= (target==me?max:target->query("max_kee")))
		return notify_fail(sprintf("%s目前并没有受伤。\n",target==me?"你":target->name()));

	if( (target != me) && (environment(me) != environment(target)))
		return notify_fail("你要疗伤的对象不在这里。\n");

	if(target==me)
		message_vision("$N盘膝跌坐，手心相对，全身真气行走周天，头顶笼罩着一丝白雾。\n",me);
	else
		message_vision("$N盘膝跌坐，双手抵住$n的后心，全身真气行走周天，头顶笼罩着一丝白雾。\n",
			me,target);

	me->add("force",-100);
	call_out("finish_healing",(busy = 5+random(5)),me,target);
	me->start_busy(busy);
	return 1;
}

void finish_healing(object me,object target)
{
	int now,eff,max,add,can;

	if(!me)
		return;

	if(!target || (environment(target) != environment(me)))
	{
		write("你疗伤的对象已经离开了这里。\n");
		return;
	}

	can = 20+me->query_skill(SKILL_FORCE,1)/8;
	now = target->query("kee");
	eff = target->query("eff_kee");
	max = target->query("max_kee");

	add = max-eff<can?max-eff:can;
	target->add("eff_kee",add);
	add = (now+add/2)>max?max-now:add/2;
	target->add("kee",add);
	tell_object(target,"你只觉得一丝清凉之气在体内行走一周，身上的伤痛好多了。\n");
	message_vision("$N行功圆满，站了起来。\n",me);
	me->stop_busy();
}
