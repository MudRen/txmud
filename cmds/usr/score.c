// score.c
// by Find.

#include <ansi.h>
#include <combat.h>
#include <mangle.h>
inherit F_CLEAN_UP;

protected string c_age(int n);
protected string graph(int val, int eff, int max);
protected string mingwang(int i);
protected string display_attr(int gift, int value);
protected string query_gongji(int gj);
protected int weapon_damage(object weapon);
protected int valid_armor(object *objs);
protected string display_credit_point(object me);

string full_string = "■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□";

int main(object me,string arg)
{
	object ob;
	int flag = 0,ap,pp,dp,pk,nk;
	string result;
	object weapon;
	mapping ar,yjj,marry;

	if(!arg) ob = me;

	else if(wizardp(me))
	{
		ob = present(arg, environment(me));
		if(!ob) ob = find_player(arg);
		if(!ob) ob = find_living(arg);
		if(!ob) return notify_fail("你要察看谁的状态？\n");
		flag = 1;
	}

	else return notify_fail("只有巫师能察看别人的状态。\n");

	result = "━━━━━━━<个人档案>━━━━━━━\n";
	result += sprintf("姓    名：%s(%s)\n",ob->query("name"),ob->query("id"));
	result += "年    龄：你是一位"+chinese_number(ob->query("age"))+"岁的"+ob->query("gender")+
		((ob->is_ghost())?"鬼魂\n":"\n");
	result += "游戏时间："+c_age(ob->query("mud_age"))+"\n";
	if(mapp(ob->query("family")))
	{
		int dusu;

		result += "你投身师门"+ob->query("family/family_name")
			+"，从师"+ob->query("family/master_name")+"学艺\n";
		if( (ob->query("class") == "shaolin")
		&& mapp(yjj = ob->query("family/yijin-jing"))
		&& (yjj["level"] > 0 || yjj["step"] > 0) )
		{
			if(yjj["level"] >= 12)
				result += "你已经将『易筋经』参悟透彻、融会贯通\n";
			else
				result += sprintf("你已经将『易筋经』第%s势第%s重参悟透彻\n",
					chinese_number(yjj["level"]+1),chinese_number(yjj["step"]));

		}
		result += "师门功绩："+query_gongji(ob->query("family/gongji"));

		if( (ob->query("class") == "tangmen")
		&& ((dusu = ob->query("family/dusu")) > 0) )
			result += sprintf("\n你目前体内融合有 %d 点毒素。\n",dusu);
	}

	result += display_credit_point(ob);

	if( mapp(marry = ob->query("marry")) )
		result += sprintf("婚姻状况：你的%s是%s(%s)\n",
				ob->query("gender")=="男性"?"爱妻":"夫君",
				marry["name"],
				capitalize(marry["id"]));

	result += sprintf(HIC"\n膂力：["+"%s"+HIC+
		"]  胆识：["+"%s"+HIC+"]  悟性：["+"%s"
		HIC+"]\n",
			display_attr(ob->query("str"),ob->query_str()),
			display_attr(ob->query("cor"),ob->query_cor()),
			display_attr(ob->query("int"),ob->query_int()));
	result += sprintf("根骨：["+"%s"+HIC+
		"]  福缘：["+"%s"+HIC+"]  容貌：["+"%s"+
		HIC"]\n\n",
			display_attr(ob->query("con"),ob->query_con()),
			display_attr(ob->query("kar"),ob->query_kar()),
			display_attr(ob->query("per"),ob->query_per()))+NOR;

	result += HIY"精  ："+graph(ob->query("gin"),ob->query("eff_gin"),ob->query("max_gin"))+"\n"NOR;
	result += HIG"气  ："+graph(ob->query("kee"),ob->query("eff_kee"),ob->query("max_kee"))+"\n"NOR;
	result += HIB"神  ："+graph(ob->query("sen"),ob->query("eff_sen"),ob->query("max_sen"))+"\n"NOR;
	if(userp(ob))
	{
	result += WHT"食物：" + graph(ob->query("food"),ob->max_food_capacity(),ob->max_food_capacity())+"\n";
	result += "饮水：" + graph(ob->query("water"),ob->max_water_capacity(),ob->max_water_capacity())+"\n\n"NOR;
	}
	ap = COMBAT_D->math_ap(ob);
	pp = COMBAT_D->math_pp(ob);
	dp = COMBAT_D->math_dp(ob);

	result += sprintf("攻 击 力：%8d  ",ap/10+1);

	weapon = ob->query_temp("weapon"); /* 右手兵器 */
	if(!weapon)
		weapon = ob->query_temp("secondary_weapon"); /* 左手兵器 */

	if(ob->query("race") == "野兽")
		result += sprintf("天然杀伤力：%4d\n",ob->query_temp("apply/damage"));
	else if(weapon)
		result += sprintf("兵器伤害度：%4d\n",weapon_damage(weapon));
	else
		result += "\n";

	result += sprintf("防 御 力：%8d  ",(dp+pp)/10+1);

	if(ob->query("race") == "野兽")
		result += sprintf("天然防护度：%4d\n",ob->query_temp("apply/armor"));

	else if(sizeof(ar = ob->query_temp("armor")))
		result += sprintf("防具防护度：%4d\n",valid_armor(values(ar)) );
	else
		result += "\n";

	result += sprintf(HIY"实战经验：%8d  潜能：%10d\n"NOR,ob->query("combat_exp"),
		(int)ob->query("potential") - (int)ob->query("learned_points"));

	if( ob->query_xuruo() )
		result += BWHT RED"你感觉身体状况非常虚弱。\n"NOR;

	pk = ob->query("PKS");
	nk = ob->query("MKS");
	result += (!(nk+pk))?"你还没有杀过人\n":("你共杀"+chinese_number(pk+nk)
		+"人，"+((pk)?"其中"+chinese_number(pk)+"人是其他玩家\n":"但没杀过其他玩家\n"));
	pk = ob->query("BPKS");
	nk = ob->query("BMKS");
	result += (!(pk+nk))?"你还没有死于别人手中过\n":("你共死亡"+chinese_number(pk+nk)
		+"次，"+((pk)?"其中"+chinese_number(pk)+"次被其他玩家杀死\n":
		"还没被其他玩家杀过\n"));

	result += sprintf("杀    气：%6d\n",ob->query("bellicosity"));
	write("\n"+result+"\n");
	return 1;

}

protected string c_age(int n)
{
	int day,hour,min;

	day = to_int(n/86400);
	n %= 86400;
	hour = to_int(n/3600);
	n %= 3600;
	min = to_int(n/60);
	return ((day)?chinese_number(day)+"天":"")
		+((hour)?chinese_number(hour)+"小时":"")
		+((min)?chinese_number(min)+"分钟":"一分钟");
}

protected string graph(int val, int eff, int max)
{
	int n,l,s;

	if(val > eff)
		val = eff;
	if(eff > max)
		eff = max;

	if(val == eff && eff == max)
		return full_string;

	n = strlen(full_string)/2;

	s = (val*n/max)*2 - 1;
	if(val && s < 1)
		s = 1;

	l = (eff*n/max)*2 -1;
	if( (eff < max) && (l >= n-1))
		l = n - 3;

	return sprintf("%s%s",!val?"":full_string[0..s],s>=l?"":blank_string[s+1..l]);
}

protected string mingwang(int i)
{
	string mw = "";

	return mw;
}

protected string query_gongji(int gj)
{
	string rnt;

	if( gj <= -50000)
		rnt = "大逆不道";
	else if( gj <= -10000)
		rnt = "倒行逆施";
	else if( gj <= -3000)
		rnt = "胡做非为";
	else if( gj < 0)
		rnt = "待罪之身";
	else if(gj < 1000)
		rnt = "无功无过";
	else if( gj <= 3000)
		rnt = "任劳任怨";
	else if( gj <= 10000)
		rnt = "忠心耿耿";
	else if( gj <= 50000)
		rnt = "劳苦功高";
	else rnt = "鞠躬尽瘁";

	return sprintf("%s (%d)\n",rnt,gj);
}

protected string display_attr(int gift, int value)
{
	if(value > gift)
		return sprintf( HIY "%3d" NOR, value );
	else if(value < gift)
		return sprintf( CYN "%3d" NOR, value );
	else
		return sprintf("%3d", value);
}

protected int weapon_damage(object weapon)
{
	int damage = weapon->query("weapon_prop/damage");
	int mangle;

	if(!(mangle = weapon->query("weapon_mangle")))
		return damage;
	if(mangle >= W_MAX_MANGLE)
		return 0;
	return (int)damage*((W_MAX_MANGLE-mangle)*100/W_MAX_MANGLE)/100;
}

protected int valid_armor(object *objs)
{
	int i,n,ret;

	if(!arrayp(objs))
		return 0;

	objs -= ({0});

	if(!n=sizeof(objs))
		return 0;

	for(i=0;i<n;i++)
	{
		int armor,mangle;

		if(!objs[i]->is_armor())
			continue;

		armor = objs[i]->query("armor_prop/armor");
		mangle = objs[i]->query("armor_mangle");
		if(!mangle)
			ret += armor;
		else if(mangle >= A_MAX_MANGLE)
			continue;
		else
			ret += armor*((A_MAX_MANGLE-mangle)*100/A_MAX_MANGLE)/100;
	}

	return ret;
}

protected string display_credit_point(object me)
{
	int n,i;
	string s_str,c_str;

	if( (me->query("age") > PROTECT_AGE)
	|| ((n = me->query_credit_point()) <= 0) )
		return "";

	s_str = (i=n/100)?sprintf(" %d 两白银",i):"";
	c_str = (i=n%100)?sprintf(" %d 文铜钱",i):"";
	return sprintf("你共有%s%s的信用点\n",s_str,c_str);
}

int help(object me)
{
	write("指令格式 : score\n"
+((wizardp(me))?"           score <对象名称>\n\n":"\n")
+"这个指令可以显示你"+((wizardp(me))?"或指定对象(含怪物)":"")+"的基本资料。\n"
+"see also : hp\n");
    return 1;
}
