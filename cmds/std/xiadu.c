// /cmds/std/xiadu.c
// 此命令用于向FOOD LIQUIT 和公共灌水、饮水处下毒
// by Find.

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string poison,where,skill;
	int level,flag = 0;
	object target,ski_ob;

	if(!stringp(arg) || sscanf(arg,"%s in %s",poison,where) != 2)
		return notify_fail("你要向什么里下什么毒？\n");

	if(where == "here")
	{
		target = environment(me);
		if(!target)
			return notify_fail("你要向什么里面下毒？\n");
		// 目前只是灌水的地方可以下毒。
		// 喝水的地方一般都是门派的厨房
		// 或是供给新手用的，暂时不能下毒。
		if(!target->query("resource/water"))
			return notify_fail("你在"+target->query("short")+
				"处四下看了看，没有找到可以下毒的地方。\n");
	}
	else
	{
		target = present(where,me);
		if(!target)
		{
			target = present(where,environment(me));
			flag = 1;
		}
		if(!target)
			return notify_fail("你要向什么里面下毒？\n");
		if(!target->is_food() && !target->is_liquid())
			return notify_fail("你要向什么里面下毒？\n");

		if(target->is_food())
		{
			if(!target->query("food_remaining"))
				return notify_fail(target->name()+"已经没什么可吃的了，下了毒也是白下。\n");
		}
		if(target->is_liquid())
		{
			if(!target->query("liquid/remaining"))
				return notify_fail(target->name()+"已经已经被喝空了，下了毒也是白下。\n");
		}
	}

	if(!ski_ob = present(poison,me))
	{
		if(!skill = SKILL_D(poison))
			return notify_fail("你要用什么毒？\n");

		if(!ski_ob = find_object(skill))
			ski_ob = load_object(skill);
		if(!objectp(ski_ob))
			return notify_fail("你要用什么毒？\n");

		if(!level = me->query_skill(poison,1))
			return notify_fail("你还不会"+to_chinese(poison)+"这项武功。\n");
		if(!function_exists("drug_in_object",ski_ob))
			return notify_fail(to_chinese(poison)+"不能用来向物品里下毒。\n");
		// 内功下毒需要一定的内力。
		if(me->query("force") < 300 || me->query("max_force") < 300)
			return notify_fail("你的内力不够，无法从体内逼出毒素。\n");
		me->add("force",-150);
		me->add("max_force",-20);
	}

	else
	{
		if(!function_exists("drug_in_object",ski_ob))
			return notify_fail(ski_ob->name()+"不能用来向物品里下毒。\n");
		// 物品的毒性是有限的，下过几次就没有毒性了。
		// query_poison() 函数用来返回此物品当前是否还有毒性。
		if(!ski_ob->query_poison())
			return notify_fail(ski_ob->name()+"里面已经没有什么毒性了。\n");
	}

	// 在 skill 里可以写这个函数来对下毒者进行判断
	// 此人是否有资格下毒、或对此人的下毒动作做一
	// 些处理。比如此项武功等级如何。
	notify_fail("你的"+to_chinese(poison)+"修为不够，没法下毒。\n");
	if(function_exists("valid_xiadu",ski_ob)
	&& !ski_ob->valid_xiadu(me,level))
		return 0;

	if(target->is_room())
	{
		target->set("no_clean_up",1);
		// 公共水源是活水，下的毒有一定的时限。

		if(!level)
			level = 50;
		target->set("drug/effect_time",time()+600+level*5);
		tell_object(me,"你迅速的往水里下了一些毒，然后装出一付若无其事的样子。\n");
	}

	else
	{
		target->stop_decay();	// 下毒后停止 decay
		tell_object(me,"你迅速的往"+target->name()+
			"里下了一些毒，然后装出一付若无其事的样子。\n");
		if(flag)
			tell_room(environment(me),me->name()+"拿起"+target->name()+"看了看又放了回去。\n");
	}

	target->set("drug/effect_func",(: call_other,base_name(ski_ob),"drug_in_object" :));
	return 1;
}

int help(object me)
{
	write(@HELP

指令格式： xiadu <毒> in <地方>

如果你身上有某种毒物或者学有某种有毒的内功，
这条指令可以让你向食物、装水的容器、可以灌
水的地方下毒。

‘毒’为你所使用的毒物或者你所学的内功名。

例如：
	向鸡腿里下鹤顶红的毒
	（当然你身上要带有鹤顶红(he dinghong)）
	xiadu he dinghong in leg

	如果你所在的地方可以灌水，
	你学有带毒的内功---唐毒(tangforce)：
	xiadu tangforce in here

用内功放毒需要行功将一些体内的毒素逼出体外
来下毒，所以自身要受一些损害。

HELP
);
	return 1;
}