//	/adm/daemons/chinese_d.c
// Modified by Find.

#include <localtime.h>

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

static string *sym_tien = ({ "��","��","��","��","��","��","��","��","��","��" });
static string *sym_dee = ({ "��","��","��","î","��","��","��","δ","��","��","��","��" });

mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

protected void create()
{
	seteuid(getuid());
	restore();
}

void remove() { save(); }

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if(!stringp(str))
		return "";

	if( !undefinedp( dict[str] ) ) return dict[str];
	else return str;
}

void remove_translate( string key )
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return;

	map_delete( dict, key );
	save();
}

void add_translate( string key, string chinz )
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return;

	dict[key] = chinz;
	save();
}
/*
void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for(i=0; i<sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date)
{
	mixed *local;

	if(!intp(date) || date <= 0)
		return "";

	local = localtime(date);

	return sprintf("%s%s��%s��%s��%sʱ%s��",
		sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
		chinese_number(local[LT_MON]+1),
		chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
		sym_dee[((local[LT_HOUR]+1)%24)/2],
		chinese_number((local[LT_MIN]+1)%2 * 2 + local[LT_MIN]/30 + 1) );
}
*/

// added by Find.
string chinese_season(int season)
{
        if(!intp(season))
                return "Error Season Type!";
        switch (season)
        {
                case 1:
                        return "����";
                case 2:
                        return "�ļ�";
                case 3:
                        return "�＾";
                case 4:
                        return "����";
                default:
                        return "Season Number Overflow!";
        }
}

protected string int_value(int amount)
{
        string output = "";
	float g_value,s_value,c_value,sum;

//	amount = to_int(amount);
	if(!amount)
		return "һ�Ĳ�ֵ��";

	if(amount < 0)
		return output;

	g_value = gold_bvalue();
	s_value = silver_bvalue();
	c_value = coin_bvalue();

	sum = to_float(amount);

        if (sum / g_value >= 1)
	{
		output += chinese_number(to_int(sum/g_value)) + "���ƽ�";
                sum -= to_int(sum/g_value)*g_value;
        }

	if (sum / s_value >= 1)
	{
		output = output + chinese_number(to_int(sum/s_value)) + "������";
		sum -= to_int(sum/s_value)*s_value;
        }

	if (sum >= c_value)
		return output += chinese_number(to_int(sum/c_value)) + "��ͭ��";

	return output;
}

protected string mapp_value(mapping value)
{
	int i,gold,silver,coin;
	string *ll;

	if(!mapp(value) || value == ([]))
		return "";

	ll = keys(value);

	for(i=0;i<sizeof(ll);i++)
	{
		if(ll[i] == "gold")
			gold = (int)value[ll[i]];
		else if(ll[i] == "silver")
			silver = (int)value[ll[i]];
		else if(ll[i] == "coin")
			coin = (int)value[ll[i]];
	}

	return sprintf("%s%s%s",(gold)?chinese_number(gold)+"���ƽ�":"",
			(silver)?chinese_number(silver)+"������":"",
			(coin)?chinese_number(coin)+"��ͭǮ":"");
}

string chinese_value(mixed value)
{
	if(mapp(value))
		return mapp_value(value);
	else if(intp(value))
		return int_value(value);
	else
		return "";
}
