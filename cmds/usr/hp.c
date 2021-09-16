// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
protected string status_color(int current, int max);

protected string display_credit_point(object me)
{
	int n,i;
	string s_str,c_str;

	if( (me->query("age") > PROTECT_AGE)
	|| ((n = me->query_credit_point()) <= 0) )
		return "";

	s_str = (i=n/100)?sprintf(" %d 两白银",i):"";
	c_str = (i=n%100)?sprintf(" %d 文铜钱",i):"";
	return sprintf(BWHT GRN"你共有%s%s的信用点 [信用点的帮助：help xinyong]\n"NOR,s_str,c_str);
}

int main(object me, string arg)
{
	object ob;
	mapping my;
 	string out;

	seteuid(getuid());
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else
		return notify_fail("只有巫师能察看别人的状态。\n");
 
	my = ob->query_entire_dbase();

	if(undefinedp(my["gin"]) || undefinedp(my["kee"]) || undefinedp(my["sen"]))
		return notify_fail("使用错误!\n"); // by Find. 比如 corpse.

	out = display_credit_point(me);

	out += sprintf(" 精  ： %s%4d/ %4d %s(%3d%%)" NOR "    灵力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
		status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
		status_color(my["atman"], my["max_atman"]),	my["atman"], my["max_atman"],
		my["atman_factor"] );

	out += sprintf(" 气  ： %s%4d/ %4d %s(%3d%%)" NOR "    内力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["kee"], my["eff_kee"]),	my["kee"], my["eff_kee"],
		status_color(my["eff_kee"], my["max_kee"]),	my["eff_kee"] * 100 / my["max_kee"],
		status_color(my["force"], my["max_force"]),	my["force"], my["max_force"],
		ob->query("force_factor") );

	out += sprintf(" 神  ： %s%4d/ %4d %s(%3d%%)" NOR "    法力： %s%4d / %4d (+%d)\n" NOR,
		status_color(my["sen"], my["eff_sen"]),	my["sen"], my["eff_sen"],
		status_color(my["eff_sen"], my["max_sen"]),	my["eff_sen"] * 100 / my["max_sen"],
		status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		my["mana_factor"] );

	out += sprintf(" %s： %s%4d/ %4d      " NOR "     潜能： %s%d\n" NOR,
		my["food"]<20&&userp(ob)?BLINK"食物"NOR:"食物",
		status_color(my["food"], ob->max_food_capacity()),
		my["food"], ob->max_food_capacity(),
		HIY, (int)ob->query("potential") - (int)ob->query("learned_points"));

	out += sprintf(" %s： %s%4d/ %4d      " NOR "     经验： %s%d\n" NOR,
		my["water"]<20&&userp(ob)?BLINK"饮水"NOR:"饮水",
		status_color(my["water"], ob->max_water_capacity()),
		my["water"], ob->max_water_capacity(),
		HIM, my["combat_exp"] );

	write(out);
	return 1;
}
 
protected string status_color(int current, int max)
{
	int percent;
 
	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}
 
int help(object me)
{
	write(@HELP
指令格式 : hp
           hp <对象名称>                   (巫师专用)
 
这个指令可以显示你或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP
    );
    return 1;
}
