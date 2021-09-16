// practice.c
// Modifide by Find.

#include <ansi.h>

inherit F_CLEAN_UP;

/* 当等级大于 250 不高于 500 时练习能增加技能等级，
 * 练习的最高等级随各人的天赋不同而小有差别，当能
 * 提升等级的以后，每练习一次也需要一点潜能。
 */
int main(object me, string arg)
{
	string skillname,sd;
	int skill, skill_basic;
	int amount;

	seteuid(getuid());
	if( me->is_fighting() )
		return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

	if( !arg ) return (__DIR__"enable")->main(me, arg);

	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(arg, 1);
	skill = me->query_skill(skillname, 1);

	if( skill < 1 )
		return notify_fail("你好像还没「学会」这项技能吧？最好先去请教别人。\n");
	if( skill_basic < 1 )
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

	notify_fail("你现在不能练习这项技能。\n");

	if(skill >= 250 && ((int)me->query("learned_points") >= (int)me->query("potential")) )
		return notify_fail("你的潜能已经发挥到极限了，无法再领悟更高深的"+to_chinese(skillname)+"。\n");

	if(skill > 500)
		return notify_fail(sprintf("你已经无法通过自己练习提高对「%s」的理解了。",
			to_chinese(skillname) ));

	if(me->query("sen") < 15)
		return notify_fail(sprintf("你目前的精神太差，无法修炼[%s]。\n",to_chinese(skillname)));

	me->start_busy(1);

	sd = (string)SKILL_D(skillname);

	if( sd->type()=="martial"
	&& skill * skill * skill/10 > me->query("combat_exp") )
		return notify_fail(sprintf("由于缺乏实战经验，你无法领悟更高深的[%s]。\n",
			to_chinese(skillname)));

	notify_fail(sprintf("你试着练习「%s」，但是并没有任何进步。\n",to_chinese(skillname)));

	if( sd->practice_skill(me) )
	{
		int pb = sd->practice_bonus();

		if(pb > -10)
			pb = -10;

		amount = (skill - 75) * (sd->black_white_ness())/100;
		if((amount < -25) && (skill < 75)) amount = -25;
		//amount += SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
		amount += (me->query_int()/2 + me->query("combat_exp")/(skill>=250 ?3000:2500))/5 + pb;
		if( amount < 1)
			amount = 1;
		if(skill>=250)
			me->add("learned_points", 1);
		me->improve_skill(skillname, amount,skill>=250 ? 0:1 );
		write(sprintf( HIY "你对「%s」的运用加深了一点理解。\n" NOR,to_chinese(skillname)));
		me->receive_damage("sen",10,"tire");
		me->stop_busy();
		return 1;
	}

        me->stop_busy();
        return 0;
}

int help(object me)
{
	write(@TEXT
指令格式：practice <技能种类>

    这个指令让你练习某个种类的技能，这个技能必须
是经过 enable 的专业技能。但每当升级的时候，必须
和你的师傅学习才能增长这项技能的级别。
    当你对于这项专业技能有了很深的根基的时候，才
有可能通过练习提高这项技能的等级，但随着各人素质
的不同练习到一定程度会遇到瓶颈，这个瓶颈是很难突
破的。

TEXT
	);
	return 1;
}
