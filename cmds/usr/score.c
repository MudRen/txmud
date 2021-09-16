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

string full_string = "����������������������������������";
string blank_string = "����������������������������������";

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
		if(!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
		flag = 1;
	}

	else return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

	result = "��������������<���˵���>��������������\n";
	result += sprintf("��    ����%s(%s)\n",ob->query("name"),ob->query("id"));
	result += "��    �䣺����һλ"+chinese_number(ob->query("age"))+"���"+ob->query("gender")+
		((ob->is_ghost())?"���\n":"\n");
	result += "��Ϸʱ�䣺"+c_age(ob->query("mud_age"))+"\n";
	if(mapp(ob->query("family")))
	{
		int dusu;

		result += "��Ͷ��ʦ��"+ob->query("family/family_name")
			+"����ʦ"+ob->query("family/master_name")+"ѧ��\n";
		if( (ob->query("class") == "shaolin")
		&& mapp(yjj = ob->query("family/yijin-jing"))
		&& (yjj["level"] > 0 || yjj["step"] > 0) )
		{
			if(yjj["level"] >= 12)
				result += "���Ѿ������׽������͸�����ڻ��ͨ\n";
			else
				result += sprintf("���Ѿ������׽����%s�Ƶ�%s�ز���͸��\n",
					chinese_number(yjj["level"]+1),chinese_number(yjj["step"]));

		}
		result += "ʦ�Ź�����"+query_gongji(ob->query("family/gongji"));

		if( (ob->query("class") == "tangmen")
		&& ((dusu = ob->query("family/dusu")) > 0) )
			result += sprintf("\n��Ŀǰ�����ں��� %d �㶾�ء�\n",dusu);
	}

	result += display_credit_point(ob);

	if( mapp(marry = ob->query("marry")) )
		result += sprintf("����״�������%s��%s(%s)\n",
				ob->query("gender")=="����"?"����":"���",
				marry["name"],
				capitalize(marry["id"]));

	result += sprintf(HIC"\n������["+"%s"+HIC+
		"]  ��ʶ��["+"%s"+HIC+"]  ���ԣ�["+"%s"
		HIC+"]\n",
			display_attr(ob->query("str"),ob->query_str()),
			display_attr(ob->query("cor"),ob->query_cor()),
			display_attr(ob->query("int"),ob->query_int()));
	result += sprintf("���ǣ�["+"%s"+HIC+
		"]  ��Ե��["+"%s"+HIC+"]  ��ò��["+"%s"+
		HIC"]\n\n",
			display_attr(ob->query("con"),ob->query_con()),
			display_attr(ob->query("kar"),ob->query_kar()),
			display_attr(ob->query("per"),ob->query_per()))+NOR;

	result += HIY"��  ��"+graph(ob->query("gin"),ob->query("eff_gin"),ob->query("max_gin"))+"\n"NOR;
	result += HIG"��  ��"+graph(ob->query("kee"),ob->query("eff_kee"),ob->query("max_kee"))+"\n"NOR;
	result += HIB"��  ��"+graph(ob->query("sen"),ob->query("eff_sen"),ob->query("max_sen"))+"\n"NOR;
	if(userp(ob))
	{
	result += WHT"ʳ�" + graph(ob->query("food"),ob->max_food_capacity(),ob->max_food_capacity())+"\n";
	result += "��ˮ��" + graph(ob->query("water"),ob->max_water_capacity(),ob->max_water_capacity())+"\n\n"NOR;
	}
	ap = COMBAT_D->math_ap(ob);
	pp = COMBAT_D->math_pp(ob);
	dp = COMBAT_D->math_dp(ob);

	result += sprintf("�� �� ����%8d  ",ap/10+1);

	weapon = ob->query_temp("weapon"); /* ���ֱ��� */
	if(!weapon)
		weapon = ob->query_temp("secondary_weapon"); /* ���ֱ��� */

	if(ob->query("race") == "Ұ��")
		result += sprintf("��Ȼɱ������%4d\n",ob->query_temp("apply/damage"));
	else if(weapon)
		result += sprintf("�����˺��ȣ�%4d\n",weapon_damage(weapon));
	else
		result += "\n";

	result += sprintf("�� �� ����%8d  ",(dp+pp)/10+1);

	if(ob->query("race") == "Ұ��")
		result += sprintf("��Ȼ�����ȣ�%4d\n",ob->query_temp("apply/armor"));

	else if(sizeof(ar = ob->query_temp("armor")))
		result += sprintf("���߷����ȣ�%4d\n",valid_armor(values(ar)) );
	else
		result += "\n";

	result += sprintf(HIY"ʵս���飺%8d  Ǳ�ܣ�%10d\n"NOR,ob->query("combat_exp"),
		(int)ob->query("potential") - (int)ob->query("learned_points"));

	if( ob->query_xuruo() )
		result += BWHT RED"��о�����״���ǳ�������\n"NOR;

	pk = ob->query("PKS");
	nk = ob->query("MKS");
	result += (!(nk+pk))?"�㻹û��ɱ����\n":("�㹲ɱ"+chinese_number(pk+nk)
		+"�ˣ�"+((pk)?"����"+chinese_number(pk)+"�����������\n":"��ûɱ���������\n"));
	pk = ob->query("BPKS");
	nk = ob->query("BMKS");
	result += (!(pk+nk))?"�㻹û�����ڱ������й�\n":("�㹲����"+chinese_number(pk+nk)
		+"�Σ�"+((pk)?"����"+chinese_number(pk)+"�α��������ɱ��\n":
		"��û���������ɱ��\n"));

	result += sprintf("ɱ    ����%6d\n",ob->query("bellicosity"));
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
	return ((day)?chinese_number(day)+"��":"")
		+((hour)?chinese_number(hour)+"Сʱ":"")
		+((min)?chinese_number(min)+"����":"һ����");
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
		rnt = "���治��";
	else if( gj <= -10000)
		rnt = "������ʩ";
	else if( gj <= -3000)
		rnt = "������Ϊ";
	else if( gj < 0)
		rnt = "����֮��";
	else if(gj < 1000)
		rnt = "�޹��޹�";
	else if( gj <= 3000)
		rnt = "������Թ";
	else if( gj <= 10000)
		rnt = "���Ĺ���";
	else if( gj <= 50000)
		rnt = "�Ϳ๦��";
	else rnt = "�Ϲ�����";

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

	s_str = (i=n/100)?sprintf(" %d ������",i):"";
	c_str = (i=n%100)?sprintf(" %d ��ͭǮ",i):"";
	return sprintf("�㹲��%s%s�����õ�\n",s_str,c_str);
}

int help(object me)
{
	write("ָ���ʽ : score\n"
+((wizardp(me))?"           score <��������>\n\n":"\n")
+"���ָ�������ʾ��"+((wizardp(me))?"��ָ������(������)":"")+"�Ļ������ϡ�\n"
+"see also : hp\n");
    return 1;
}
