/******************************************
 * criminal_record.c
 *
 * 此物件用于管理所有形式的犯罪的判别、罪犯通缉、
 * 布告、销案、为民除害的奖励等一切与犯罪有关的
 * 事宜。
 *
 *
 * 目前犯罪种类有：
 * 1. 恶性杀人犯。
 * 2. 盗窃犯。
 *
 *		By Find.
 ******************************************/

inherit F_NATURE;
inherit F_SAVE;
inherit F_DBASE;

class family
{
	string k_name;
	string k_id;
	string name;
	string id;
	int master;
	string date;
}

mapping family_crime = ([]);

mapping criminals = ([]);

/*
采取记录格式：
"find" : ([
	"crime"  : "killer", // 案由。
	"name"   : "发现号", // chinese name.
	"family" : "飞云庄", // family.
])
*/

void create()
{
	seteuid(getuid());
	set("channel_id", "罪案精灵");
	restore();
}

string query_save_file() { return DATA_DIR+"crimed";}

string query_placard() /* 此函数管理各城门的布告内容, 长安北门 is an example. */
{
	string head,end,*cris,content;
	int year,month;

	month = query_month();
	year = query_year();

	head ="
	 《官府通告》
---------------------------------\n";

	end ="---------------------------------\n\t"
		+MUD_NAME+((year == 0)? "元":chinese_number(year))+
		"年"+chinese_number(month)+"月\n";

/*********************************
布告内容例如下：

△ 疯狂杀人犯 Find，极度危险。
   曾用名：发现号。
   现  名：(不祥)。
   线  索：此人原为飞云庄弟子。
**********************************/

	if(criminals == ([]) || !sizeof(cris = keys(criminals)))
	{
		content = "  由于官府治理得力，天下一片祥和，
户部大臣上奏朝廷请求减租减税，朝
廷正在讨论。\n";
		return head + content + end;
	}
}

string query_family_placard(string cls)
{


}

// 门派仇杀：
// 同门互杀 不管
void pass_family_crime(object killer,object victim)
{
	string v_class,k_class;
	class family ff;
	int year,month,day;

	if( !killer
	|| !victim
	|| !previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	if(!userp(killer) )
		return;

	if(!userp(victim) && !victim->is_master())
		return;

	k_class = killer->query("class");
	v_class = victim->query("class");

	// 同门对杀另外处理。
	if( !v_class || k_class == v_class )
		return;

	// 先检查是不是报仇
	if( stringp(k_class) && userp(victim) && !undefinedp(family_crime[k_class]) )
	{
		class family *crimes;
		int n;
		int flag;
		string id = victim->query("id");

		crimes = family_crime[k_class];
		if( crimes && (n = sizeof(crimes)) )
		{
			for(int i=0;i<n;i++)
			{
				// 被杀一次就一笔勾销。
				if(crimes[n]->k_id == id)
				{
					crimes[n] = 0;
					flag++;
				}
			}

			if(flag) // 报仇
			{
				crimes -= ({0});
				family_crime[k_class] = crimes;
				save();
				return;
			}
		}
	}

	ff = new(class family);
	ff->k_name = killer->query("name");
	ff->k_id = killer->query("id");
	ff->name = victim->query("name");
	ff->id = victim->query("id");
	ff->master = userp(victim)?0:1;

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	ff->date = sprintf("%s创世%s年%s月%s日",MUD_NAME,
		!year?"元":chinese_number(year),
		chinese_number(month),
		chinese_number(day) );

	if(undefinedp(family_crime[v_class]))
		family_crime[v_class] = ({ ff });
	else
		family_crime[v_class] += ({ ff });
	save();
}
