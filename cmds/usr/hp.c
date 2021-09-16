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

	s_str = (i=n/100)?sprintf(" %d ������",i):"";
	c_str = (i=n%100)?sprintf(" %d ��ͭǮ",i):"";
	return sprintf(BWHT GRN"�㹲��%s%s�����õ� [���õ�İ�����help xinyong]\n"NOR,s_str,c_str);
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
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
	my = ob->query_entire_dbase();

	if(undefinedp(my["gin"]) || undefinedp(my["kee"]) || undefinedp(my["sen"]))
		return notify_fail("ʹ�ô���!\n"); // by Find. ���� corpse.

	out = display_credit_point(me);

	out += sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d / %4d (+%d)\n" NOR,
		status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
		status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
		status_color(my["atman"], my["max_atman"]),	my["atman"], my["max_atman"],
		my["atman_factor"] );

	out += sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d / %4d (+%d)\n" NOR,
		status_color(my["kee"], my["eff_kee"]),	my["kee"], my["eff_kee"],
		status_color(my["eff_kee"], my["max_kee"]),	my["eff_kee"] * 100 / my["max_kee"],
		status_color(my["force"], my["max_force"]),	my["force"], my["max_force"],
		ob->query("force_factor") );

	out += sprintf(" ��  �� %s%4d/ %4d %s(%3d%%)" NOR "    ������ %s%4d / %4d (+%d)\n" NOR,
		status_color(my["sen"], my["eff_sen"]),	my["sen"], my["eff_sen"],
		status_color(my["eff_sen"], my["max_sen"]),	my["eff_sen"] * 100 / my["max_sen"],
		status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		my["mana_factor"] );

	out += sprintf(" %s�� %s%4d/ %4d      " NOR "     Ǳ�ܣ� %s%d\n" NOR,
		my["food"]<20&&userp(ob)?BLINK"ʳ��"NOR:"ʳ��",
		status_color(my["food"], ob->max_food_capacity()),
		my["food"], ob->max_food_capacity(),
		HIY, (int)ob->query("potential") - (int)ob->query("learned_points"));

	out += sprintf(" %s�� %s%4d/ %4d      " NOR "     ���飺 %s%d\n" NOR,
		my["water"]<20&&userp(ob)?BLINK"��ˮ"NOR:"��ˮ",
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
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ���ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}
