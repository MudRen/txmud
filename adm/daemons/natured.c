//	/adm/daemons/natured.c
// by Find.

/********************************************************
 * Mudlib �����д��������ֱ���ʱ�ϴ�������������    *
 * �ĺ�� - debug.log ��������ÿ 1-2 ��������1M���ٶ��� *
 * �ͣ��Դ��ļ������߱༭һ��Ҫ���С�ģ�               *
 *                        ^^^^^^^                       *
 ********************************************************/

#pragma optimize

#include <ansi.h>

#define TIME_TICK (time())
#define MONTH_BEGAIN ({1,32,60,91,121,152,182,213,244,274,305,335})

static int current_day_phase;

mapping *day_phase;

/*
 * begain spring at  2.4. the  35's day of years.
 * begain summer at  5.6. the 126's day of years.
 * begain autumn at  8.8. the 220's day of years.
 * begain winter at 11.7. the 311's day of years.
 * You can change the day just in function update_season()
 */

protected void do_daily_affair(); // ����һЩ�ճ�������
static int update_file_database = 0;
static int begain_paiming = 0;
static int paimai_dahui = 0;
static int fresh_news = 0;
protected void control_shops(int i);	// �����̵�Ŀ�������ʾ��Ϣ��
protected void update_season();
protected void begain_weather();
protected void update_weather(int p,int flag);
protected void do_user_effect();
string weather_now(int p);

#define DAY_FILE	"/adm/etc/nature/inmud_day_count"
static int year;
static int current_season;
static int day;
static int weather_flag = 0;
static mapping weather_msg;
static mapping current_weather_msg;
static string weather_room_description;
static string current_weather_effect;
static string weather_degree;

mapping spring_weather = ([
	"wind": ([ "begain" : ([ "info"   : "����й�����һ˿΢��",
				 "look"   : "����һ˿����Ĵ���������",
				 "better" : "�罥����ͣ��",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "�����������£��һƬ���ƣ���Խ��Խ����",
				 "look"   : "�Ʋ���ͷ���Ͼۼ����绹�ڹ���",
				 "better" : "�罥����С�ˣ��Ʋ�������ɢ��",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "��Խ��Խ���ˣ�����ó����ڿ��з���",
				 "look"   : "�����ŷ�ɳ��ʯ����ؼ�һƬ�Ұ�",
				 "better" : "�翪ʼС��",
				 "length" : 100,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "���ʵ����Ʈ�ϼ��䵭���İ���",
				 "look"   : "տ����ӳ�ż�����ƣ�һƬ��������",
				 "better" : "�Ʋ���Զ��Ʈȥ����ձ�����ϴ",
				 "length" : 150,]),

		   "last"   : ([ "info"   : "���ƽ���Ʈ�˹���",
				 "look"   : "����������ܲ���ż�����м����������",
				 "better" : "����������ɢ����̫��¶�˳���",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "���ż������ף���ʼ������",
				 "look"   : "���������Ĵ��������Ŵ��",
				 "better" : "��������ͣ������",
				 "length" : 100,]),
		]),

	"fog"  : ([ "begain" : ([ "info"  : "һ˿�����ڿ���������",
				  "look"  : "�������֣�������Щ��ʪ",
				  "better": "��������ɢ���������ָ�����",
				  "length": 180,]),

		    "last"   : ([ "info"  : "����Խ��Խ����",
				  "look"  : "����������Ũ�ص�����",
				  "better": "Ũ��������ʼ��ɢ",
				  "length": 200,]),
		 ]),
	]);

mapping summer_weather = ([
	"wind": ([ "begain" : ([ "info"   : "����й�����һ˿΢��",
				 "look"   : "���ʵ���չ���һ˿΢��",
				 "better" : "�罥����ͣ��",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "Զ������������Ʈ�˹�������Խ��Խ����",
				 "look"   : "���Ŵ�磬ͷ�������ܲ�",
				 "better" : "�罥����С�ˣ����ƿ�ʼƮɢ��ȥ",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "�����Ŵ��ư�ö��£���ؼ�һƬ�谵",
				 "look"   : "����������������������������",
				 "better" : "�꽥����ͣ�ˣ��绹�ڹ���",
				 "length" : 100,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "һЩСС���ƶ�����������",
				 "look"   : "���������Ư���ż������",
				 "better" : "�ƶ�ɢȥ����ձ�����ϴ",
				 "length" : 150,]),

		   "last"   : ([ "info"   : "�ƶ俪ʼѸ�پۼ���ѹ��",
				 "look"   : "�����Ʋ�ѹ��ͷ������������",
				 "better" : "�����Ʋ�������ɢ����",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "���ż������ף���ʼ������",
				 "look"   : "�����������������ţ�������Ȼ����",
				 "better" : "��������ͣ������",
				 "length" : 100,]),
		]),
	]);

mapping autumn_weather = ([
	"wind": ([ "begain" : ([ "info"   : "����й�����һ˿΢��",
				 "look"   : "����й���һ˿����",
				 "better" : "�罥����ͣ��",
				 "length" : 140,]),

		   "last"   : ([ "info"   : "������������������ҲԽ��Խ����",
				 "look"   : "��ɫ�������ݻƵ�ҶƬ����׷״���",
				 "better" : "�罥����С�ˣ���Ҳ��ʼ����",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "��Խ��Խ���ˣ�����ó����ڿ��з���",
				 "look"   : "�������ɳʯ����Ҷ�ڿ��з���",
				 "better" : "������е�С��",
				 "length" : 120,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "���䵭�����Ʋ�ױ�������ʵ����",
				 "look"   : "�����ˬ��տ����ӳ�ż������",
				 "better" : "�Ʋ�������Զ��Ʈȥ",
				 "length" : 140,]),

		   "last"   : ([ "info"   : "���ƽ���£�����",
				 "look"   : "��ɫ�谵��Զ��ż��������������",
				 "better" : "̫��������¶���Ʋ㣬������������",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "�谵�����������С��",
				 "look"   : "���׷����£�����Խ��Խ����",
				 "better" : "��������ͣ������",
				 "length" : 110,]),
		]),

	"fog"  : ([ "begain" : ([ "info"  : "һ˿�����ڿ���������",
				  "look"  : "�������֣�������Щ����",
				  "better": "��������ɢ���������ָ�����",
				  "length": 180,]),

		    "last"   : ([ "info"  : "����Խ��Խ����",
				  "look"  : "����������Ũ�ص�����������Ϯ��",
				  "better": "Ũ��������ʼ��ɢ��",
				  "length": 200,]),
		 ]),
	]);

mapping winter_weather = ([
	"wind": ([ "begain" : ([ "info"   : "����ı����������",
				 "look"   : "����й��ź���ı���",
				 "better" : "�罥����ͣ��",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "��Խ��Խ���ˣ�����ҲԽ��Խ����",
				 "look"   : "��ɫ��������ͺ����֦�ڷ���Ť��",
				 "better" : "�罥����С�ˣ�����Ҳ��ʼ����ô����",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "������𣬺�Х��ɨ�����",
				 "look"   : "�����ı����Х��ɨ�����",
				 "better" : "������е�С��",
				 "length" : 100,]),
		 ]),

       "snow" : ([ "begain" : ([ "info"   : "������ʼ��������",
				 "look"   : "������������",
				 "better" : "���ƽ���ɢȥ��̫��������",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "�����Ŀ��п�ʼƮ����Сѩ��",
				 "look"   : "��ɫ���������ѩ��Ʈ�����",
				 "better" : "ѩ������ͣ�ˣ���ɫ��Ȼ����",
				 "length" : 110,]),

		   "finish" : ([ "info"   : "����ˣ�����Ʈ���˶�ë��ѩ",
				 "look"   : "����Ʈ�Ŷ�ë��ѩ������һƬ��װ�ع�",
				 "better" : "ѩ��ʼС��",
				 "length" : 150,]),
		]),

	]);

protected mapping *read_table(string file);
void init_day_phase();

protected void create()
{
	seteuid(getuid());
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;
	string *file_line;
	int last_day = 0;

	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes


	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

	/*
	 *  added by Find.
	 *  mud ���ʱ��һ��Ϊ 1440 ��,Ҳ����24����
	 *  һ�� 365 ��,Ҳ���� 146 ��Сʱ,ÿ������ƽ��
	 *  ��ʮ���Сʱ,һ���ļ�ѭ��Ҫ��Լ6���һ��,
	 *  �����뼾����ص����ʱҪ��ֿ��ǵ���һ�㡣
	 *  ���ڵ��趨Ϊ:2��4�� ����;5��6�� ����;
	 *  8��8�� ����; 11��7�� ����
	 *  24����������Ϸ��û�б�Ҫ,����ֻȡ���ĸ�����.
	 *  weather_msg ����ݲ�ͬ�ļ����в�ͬ�ı���.
	 */

	/*  ΪʲôҪ����������жϳ����أ�
	 *  ��ǰ�� natured ʵ����ֻ�ܰ���Ϊ��λ�ֻأ�
	 *  �� mud ��һ��ֻ��24���ӣ����Դ�ɲ��ؿ���
	 *  ��������������ļ��ֻ�������Ϊ��λ�ģ�һ��
	 *  �ֻ�Ҫ����࣬�ҿ��������һ������������ mud
	 *  �ͻ�ֻ�ܿ�����ʵ�����еļ��ڻ�������ڵ���һ
	 *  ����������������,sigh.˭���ܱ�֤�������첻��
	 *  ���أ������ͻ����ĳЩ������Զ�������������
	 *  ����ÿ����һ�춼Ҫ���� day_count �ļ����ѵ�ǰ
	 *  mud ��� day ��¼���������� mud ��ļ��ھͻ�
	 *  ��Զ��˳��ѭ����ȥ��
	 */

	if( file_size(DAY_FILE) != -1 )
	{
		file_line = explode(read_file(DAY_FILE), "\n");
		for(i=0; i<sizeof(file_line); i++)
		{
			if( file_line[i]=="" || file_line[i][0]=='#' ) continue;
			if( sscanf(file_line[i],"year %d:day %d",year,last_day) == 2)
				break;
		}
	}

	if(!last_day)
		day = local[7];
	else day = last_day;

	if( day < 35 || day >= 311 )
	{
		current_season = 4;	// ����
		weather_msg = winter_weather;
	}

	else if( day >= 220 && day < 311 )
	{
		current_season = 3;	// �＾
		weather_msg = autumn_weather;
	}

	else if( day >= 126 && day < 220 )
	{
		current_season = 2;	// �ļ�
		weather_msg = summer_weather;
	}

	else
	{
		current_season = 1;	// ����
		weather_msg = spring_weather;
	}

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

string day_or_night()
{
	switch( current_day_phase )
	{
		case 0:
			return "night "+find_call_out("update_day_phase");
			break;
		case 1:
			return "day "+(find_call_out("update_day_phase")+720);
			break;
		case 2:
			return "day "+(find_call_out("update_day_phase")+540);
			break;
		case 3:
			return "day "+(find_call_out("update_day_phase")+360);
			break;
		case 4:
			return "day "+(find_call_out("update_day_phase")+180);
			break;
		case 5:
			return "day "+find_call_out("update_day_phase");
			break;
		case 6:
			return "night "+(find_call_out("update_day_phase")+480);
			break;
		case 7:
			return "night "+(find_call_out("update_day_phase")+240);
			break;
	}
}

protected void update_day_phase()
{
	remove_call_out("update_day_phase");

	current_day_phase = (++current_day_phase) % sizeof(day_phase);
	call_out("update_day_phase", day_phase[current_day_phase]["length"]);

	do_daily_affair(); // �����ճ�����

	if( current_day_phase == 1 )  // ̫�������ʱ���������
	{
		day += 1;
		if( day > 365 )
		{
			day = 1;
			year += 1;
			message("vision", BGRN HIY BLINK"�µ�һ�꿪ʼ�ˡ�\n" NOR,users());
		}

		write_file(DAY_FILE,sprintf("year %d:day %d\n",year,day),1);
		update_season();
		if( (random(50) < 20) && !weather_flag )  // ������������ĸ���
			begain_weather();
	}

	if(!weather_flag)
		message("outdoor:vision", "��������"+day_phase[current_day_phase]["time_msg"] + "\n", users());

	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	control_shops(current_day_phase);
}

// Ŀǰ�����������ô�����Ժ���԰��ⲿ���ó�ȥ
// ����һ����ʱ�����õ� daemon ������������Ĵ�
// ����ȫ������������ȷ�Ķ�ʱ��

// Ŀǰ�Ѿ��Ƴ�
protected void do_daily_affair()
{
	if(current_day_phase == 1) 	// ������ǿ����ǡ�
		users()->delete_temp("init_qiangdao");
}

protected void control_shops(int i)
{
	object *ob,env;
	int c;
	string file;

	if( i ==  1 )
	{
		ob = users();
		for(c=0;c<sizeof(ob);c++)
		{
			if( (env = environment(ob[c]))
			&& file = function_exists("open_close_door", env))
			{
				// Ϊֱ�ۺͱ����Ա������⣬������ת����
				// begin_day ��begin_night �����ַ������롣
				call_other(env,"open_close_door","begin_day",ob[c]);
			}
		}
		return;
	}

	if( i ==  6 )
	{
		ob = users();
		for(c=0;c<sizeof(ob);c++)
		{
			if( (env = environment(ob[c]))
			&& function_exists("open_close_door", env))
				call_other(env,"open_close_door","begin_night",ob[c]);
		}
		return;
	}

}

protected void begain_weather()
{
	string *weather_effect;

	if(!mapp(weather_msg))
		return;
	weather_effect = keys(weather_msg);
	if(!arrayp(weather_effect) || !sizeof(weather_effect))
		return;

	current_weather_effect = weather_effect[random(sizeof(weather_effect))];
	current_weather_msg = weather_msg[current_weather_effect];
	update_weather(0,2);
}

protected void update_weather(int p,int flag)
{
	string *course;

	course = keys(current_weather_msg);

	remove_call_out("update_weather");

	if(p < 0)
	{
		weather_flag = 0;
		message("outdoor:vision", "��������"+current_weather_msg[weather_now(0)]["better"] + "��\n", users());
		return;

	}
	weather_flag = 1;
	weather_room_description = current_weather_msg[weather_now(p)]["look"];

	call_out("effect_to_users",2,p);  // ����״������Ҳ���Ӱ��.

	if(flag == 1)
	{
	message("outdoor:vision", "��������"+current_weather_msg[weather_now(p+1)]["better"] + "��\n", users());
	call_out("update_weather",current_weather_msg[weather_now(p)]["length"],(p-1),1);
	}

	else
	{
	message("outdoor:vision", "��������"+current_weather_msg[weather_now(p)]["info"] + "��\n", users());

	if(random(100) < 70)
		{
		if((p+2) > sizeof(course))
			call_out("update_weather",current_weather_msg[weather_now(p)]["length"],(p-1),1);
		else
			call_out("update_weather",current_weather_msg[weather_now(p)]["length"],(p+1),2);
		}
	else
		call_out("update_weather",current_weather_msg[weather_now(p)]["length"],(p-1),1);
	}
}

string weather_now(int p)
{
	switch ( p )
	{
		case 0:
			weather_degree = "begain";
			return weather_degree;
			break;
		case 1:
			weather_degree = "last";
			return weather_degree;
			break;
		case 2:
			weather_degree = "finish";
			return weather_degree;
			break;
	}
}

void effect_to_users(int p)
{
	switch ( current_weather_effect )
	{
	case "wind":
		if( (p == 2) || (current_season == 4 && p >=1) )
			do_user_effect();
		return;
		break;
	case "cloudy":
		if( (current_season == 1 && p == 2)
		||  (current_season == 3 && p == 2))
			do_user_effect();
		return;
		break;
	case "snow":
		if( p >=1 )
			do_user_effect();
		return;
		break;
	}
}

protected void do_user_effect()
{
	object *ob;
	int i;

	ob = users();
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("netdead"))
			continue;
		if(!environment(ob[i]))
			continue;
		if(!environment(ob[i])->query("outdoors"))
			continue;
		if(ob[i]->is_ghost())
			continue;
		ob[i]->weather_effect(current_weather_effect);
	}
}

protected void update_season()
{
	switch ( day )
	{
	case 35:
		weather_msg = spring_weather;
		current_season = 1;	// ����
		// ���ڵı������ֻ���ڻ��⣬���Դ�messageû����outdoor��������Ҷ��ܿ���������Ϣ��
		message("vision", "�� �� �� �����쵽���ˣ�������ʼתů������𽥳��ֳ�һƬ����������\n",users());
		if( !undefinedp( "spring_season" ) )
			call_other( this_object(), "spring_season" );
		break;
	case 126:
		weather_msg = summer_weather;
		current_season = 2;	// �ļ�
		message("vision", "�� �� �� �����ȵ��ļ���ʼ�ˣ����Ҳ��ʼ����궯������\n",users());
		if( !undefinedp( "summer_season" ) )
			call_other( this_object(), "summer_season" );
		break;
	case 220:
		weather_msg = autumn_weather;
		current_season = 3;	// �＾
		message("vision", "�� �� �� ����ɫ�����쿪ʼ�ˣ������ջ��Լ����ڸ��ŵĳɹ���ʱ���ˡ�\n",users());
		if( !undefinedp( "autumn_season" ) )
			call_other( this_object(), "autumn_season" );
		break;
	case 311:
		weather_msg = winter_weather;
		current_season = 4;	// ����
		message("vision", "�� �� �� ���������ٴ�أ����翪ʼ��Х����Ű�������硣\n",users());
		if( !undefinedp( "winter_season" ) )
			call_other( this_object(), "winter_season" );
		break;
	}
}

string season_chat()
{
	switch ( current_season )
	{
	case 1:
		return "�������";
		break;
	case 2:
		return "��������";
		break;
	case 3:
		return "�����ˬ";
		break;
	case 4:
		return "��ѩ����";
		break;
	}
}

string query_weather()
{
	if(weather_flag)
		return sprintf("%s %s",current_weather_effect,weather_degree);
	else return "clear now";
}

int query_day(int *month_day)
{
	if(!month_day)
		return day;

	if(sizeof(month_day) == 2
	&& month_day[0]>=1
	&& month_day[0]<=12
	&& month_day[1]>=1
	&& month_day[1]<=31)
		return (int)MONTH_BEGAIN[month_day[0]-1]+month_day[1]-1;
	else
		return 0;
}

int query_season()
{
	return current_season;
}

int query_year()
{
	return year;
}

string query_month()
{
	int current_day,month;
	int real_day;

	if(current_day_phase == 7 || current_day_phase == 0)
		real_day = day + 1;
	else real_day = day;

	if(real_day <= 31)
	{
		month = 1;
		current_day = real_day;
	}

	else if(real_day > 31 && real_day <= 59)
	{
		month = 2;
		current_day = real_day - 31;
	}

	else if(real_day > 59 && real_day <= 90)
	{
		month = 3;
		current_day = real_day - 59;
	}

	else if(real_day > 90 && real_day <= 120)
	{
		month = 4;
		current_day = real_day - 90;
	}

	else if(real_day > 120 && real_day <= 151)
	{
		month = 5;
		current_day = real_day - 120;
	}

	else if(real_day > 151 && real_day <= 181)
	{
		month = 6;
		current_day = real_day - 151;
	}

	else if(real_day > 181 && real_day <= 212)
	{
		month = 7;
		current_day = real_day - 181;
	}

	else if(real_day > 212 && real_day <= 243)
	{
		month = 8;
		current_day = real_day - 212;
	}

	else if(real_day > 243 && real_day <= 273)
	{
		month = 9;
		current_day = real_day - 243;
	}

	else if(real_day > 273 && real_day <= 304)
	{
		month = 10;
		current_day = real_day - 273;
	}

	else if(real_day > 304 && real_day <= 334)
	{
		month = 11;
		current_day = real_day - 304;
	}

	else
	{
		month = 12;
		current_day = real_day - 334;
	}

	return sprintf("month %d:day %d",month,current_day);
}

int query_current_time()
{
	switch( current_day_phase )
		{
		case 0:
			return 240 + 240 - find_call_out("update_day_phase");
		case 1:
			return 480 + 120 - find_call_out("update_day_phase");
		case 2:
			return 600 + 180 - find_call_out("update_day_phase");
		case 3:
			return 780 + 180 - find_call_out("update_day_phase");
		case 4:
			return 960 + 180 - find_call_out("update_day_phase");
		case 5:
			return 1140 + 180 - find_call_out("update_day_phase");
		case 6:
			return 1320 + 120 - find_call_out("update_day_phase");
		case 7:
			return 240 - find_call_out("update_day_phase");
		}
}

void event_noon()
{
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "����̫��������յ������룬�������ķ�����ʼ��ʧ�ˡ�\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

// for ��·���١�
void event_sunrise()
{
	object *ob;

	ob = filter_array(children("/std/room/npc/qiangdao_t"),(: clonep :));
	ob->do_remove();
}

string outdoor_room_description()
{
	if(weather_flag)
		return "    " + weather_room_description + "��\n";
	else return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}

protected mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}

mapping *query_day_phase() { return day_phase; }
