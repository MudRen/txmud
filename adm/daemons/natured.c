//	/adm/daemons/natured.c
// by Find.

/********************************************************
 * Mudlib 运行中此物件如出现编译时断错误会造成灾难性    *
 * 的后果 - debug.log 会至少以每 1-2 秒钟增长1M的速度膨 *
 * 胀，对此文件的在线编辑一定要万分小心！               *
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

protected void do_daily_affair(); // 控制一些日常事务处理
static int update_file_database = 0;
static int begain_paiming = 0;
static int paimai_dahui = 0;
static int fresh_news = 0;
protected void control_shops(int i);	// 控制商店的开关门提示信息。
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
	"wind": ([ "begain" : ([ "info"   : "天空中刮起了一丝微风",
				 "look"   : "带着一丝凉意的春风拂面而来",
				 "better" : "风渐渐的停了",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "慢慢的天空中拢上一片轻云，风越刮越大了",
				 "look"   : "云层在头顶上聚集，风还在刮着",
				 "better" : "风渐渐的小了，云层慢慢的散开",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "风越刮越大了，扬起得尘土在空中飞舞",
				 "look"   : "大风带着飞沙走石，天地间一片灰暗",
				 "better" : "风开始小了",
				 "length" : 100,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "晴朗的天空飘上几朵淡淡的白云",
				 "look"   : "湛蓝的映着几朵白云，一片春光明媚",
				 "better" : "云彩往远处飘去，天空碧蓝如洗",
				 "length" : 150,]),

		   "last"   : ([ "info"   : "乌云渐渐飘了过来",
				 "look"   : "天空中乌云密布，偶尔还有几声滚雷响过",
				 "better" : "乌云慢慢消散开，太阳露了出来",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "随着几声闷雷，开始下雨了",
				 "look"   : "淅淅沥沥的春雨滋润着大地",
				 "better" : "雨慢慢的停了下来",
				 "length" : 100,]),
		]),

	"fog"  : ([ "begain" : ([ "info"  : "一丝薄雾在空气中弥漫",
				  "look"  : "薄雾笼罩，空气有些潮湿",
				  "better": "薄雾慢慢散开，天气恢复晴朗",
				  "length": 180,]),

		    "last"   : ([ "info"  : "雾气越来越重了",
				  "look"  : "空中弥漫着浓重的雾气",
				  "better": "浓雾慢慢开始消散",
				  "length": 200,]),
		 ]),
	]);

mapping summer_weather = ([
	"wind": ([ "begain" : ([ "info"   : "天空中刮起了一丝微风",
				 "look"   : "晴朗的天空刮着一丝微风",
				 "better" : "风渐渐的停了",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "远方的乌云慢慢飘了过来，风越刮越大了",
				 "look"   : "刮着大风，头顶阴云密布",
				 "better" : "风渐渐的小了，乌云开始飘散开去",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "雨随着大风瓢泼而下，天地间一片昏暗",
				 "look"   : "大雨滂沱，还夹杂着雷声和闪电",
				 "better" : "雨渐渐的停了，风还在刮着",
				 "length" : 100,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "一些小小的云朵出现在天空中",
				 "look"   : "蓝蓝的天空漂浮着几朵白云",
				 "better" : "云朵散去，天空碧蓝如洗",
				 "length" : 150,]),

		   "last"   : ([ "info"   : "云朵开始迅速聚集、压低",
				 "look"   : "厚厚的云层压在头顶，空气闷热",
				 "better" : "厚厚的云层慢慢消散开了",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "随着几声闷雷，开始下雨了",
				 "look"   : "雨在淅淅沥沥的下着，天气依然闷热",
				 "better" : "雨慢慢的停了下来",
				 "length" : 100,]),
		]),
	]);

mapping autumn_weather = ([
	"wind": ([ "begain" : ([ "info"   : "天空中刮起了一丝微风",
				 "look"   : "天空中刮着一丝凉风",
				 "better" : "风渐渐的停了",
				 "length" : 140,]),

		   "last"   : ([ "info"   : "天慢慢的阴下来，风也越刮越大了",
				 "look"   : "天色阴沉，枯黄的叶片被风纷纷吹落",
				 "better" : "风渐渐的小了，天也开始放晴",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "风越刮越大了，扬起得尘土在空中飞舞",
				 "look"   : "大风带起的沙石和落叶在空中飞扬",
				 "better" : "风好象有点小了",
				 "length" : 120,]),
		 ]),

     "cloudy" : ([ "begain" : ([ "info"   : "几朵淡淡的云彩妆点著清朗的天空",
				 "look"   : "秋高气爽，湛蓝的映着几朵白云",
				 "better" : "云彩慢慢往远处飘去",
				 "length" : 140,]),

		   "last"   : ([ "info"   : "阴云渐渐拢上天空",
				 "look"   : "天色昏暗，远处偶尔传来几声闷雷",
				 "better" : "太阳渐渐的露出云层，天慢慢的晴了",
				 "length" : 120,]),

		   "finish" : ([ "info"   : "昏暗的天空下起了小雨",
				 "look"   : "雨点纷纷落下，天气越来越冷了",
				 "better" : "雨慢慢的停了下来",
				 "length" : 110,]),
		]),

	"fog"  : ([ "begain" : ([ "info"  : "一丝薄雾在空气中弥漫",
				  "look"  : "薄雾笼罩，空气有些阴冷",
				  "better": "薄雾慢慢散开，天气恢复晴朗",
				  "length": 180,]),

		    "last"   : ([ "info"  : "雾气越来越重了",
				  "look"  : "空中弥漫着浓重的雾气，冷意袭人",
				  "better": "浓雾慢慢开始消散了",
				  "length": 200,]),
		 ]),
	]);

mapping winter_weather = ([
	"wind": ([ "begain" : ([ "info"   : "干冷的北风刮起来了",
				 "look"   : "天空中刮着寒冷的北风",
				 "better" : "风渐渐的停了",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "风越刮越大了，空气也越来越冷了",
				 "look"   : "天色阴沉，光秃的树枝在风中扭曲",
				 "better" : "风渐渐的小了，天气也开始不那么冷了",
				 "length" : 150,]),

		   "finish" : ([ "info"   : "北风狂起，呼啸着扫过大地",
				 "look"   : "凛冽的北风呼啸着扫过大地",
				 "better" : "风好象有点小了",
				 "length" : 100,]),
		 ]),

       "snow" : ([ "begain" : ([ "info"   : "天气开始阴沉下来",
				 "look"   : "天气阴沉寒冷",
				 "better" : "阴云渐渐散去，太阳出来了",
				 "length" : 120,]),

		   "last"   : ([ "info"   : "阴沉的空中开始飘起了小雪花",
				 "look"   : "天色阴沉，点点雪花飘落而下",
				 "better" : "雪慢慢的停了，天色依然阴沉",
				 "length" : 110,]),

		   "finish" : ([ "info"   : "起风了，空中飘起了鹅毛大雪",
				 "look"   : "空中飘着鹅毛大雪，世界一片银装素裹",
				 "better" : "雪开始小了",
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
	 *  mud 里的时间一天为 1440 秒,也就是24分钟
	 *  一年 365 天,也就是 146 个小时,每个季节平均
	 *  三十多个小时,一个四季循环要大约6天多一点,
	 *  制作与季节相关的情节时要充分考虑到这一点。
	 *  季节的设定为:2月4日 立春;5月6日 立夏;
	 *  8月8日 立秋; 11月7日 立冬
	 *  24个节气在游戏里没有必要,所以只取这四个节气.
	 *  weather_msg 会根据不同的季节有不同的表现.
	 */

	/*  为什么要做下面这个判断程序呢？
	 *  以前的 natured 实际上只能按天为单位轮回，
	 *  而 mud 里一天只有24分钟，所以大可不必考虑
	 *  当机的情况，但四季轮回是以年为单位的，一个
	 *  轮回要六天多，我考虑如果是一个经常当机的 mud
	 *  就会只能看到现实生活中的季节或这个季节的下一
	 *  个季节这两个季节,sigh.谁又能保证至少六天不当
	 *  机呢，这样就会出现某些季节永远看不到的情况，
	 *  所以每增加一天都要更新 day_count 文件，把当前
	 *  mud 里的 day 记录下来，这样 mud 里的季节就会
	 *  永远按顺序循环下去。
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
		current_season = 4;	// 冬季
		weather_msg = winter_weather;
	}

	else if( day >= 220 && day < 311 )
	{
		current_season = 3;	// 秋季
		weather_msg = autumn_weather;
	}

	else if( day >= 126 && day < 220 )
	{
		current_season = 2;	// 夏季
		weather_msg = summer_weather;
	}

	else
	{
		current_season = 1;	// 春季
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

	do_daily_affair(); // 处理日常事务。

	if( current_day_phase == 1 )  // 太阳升起的时候更换季节
	{
		day += 1;
		if( day > 365 )
		{
			day = 1;
			year += 1;
			message("vision", BGRN HIY BLINK"新的一年开始了。\n" NOR,users());
		}

		write_file(DAY_FILE,sprintf("year %d:day %d\n",year,day),1);
		update_season();
		if( (random(50) < 20) && !weather_flag )  // 出现气候现象的概率
			begain_weather();
	}

	if(!weather_flag)
		message("outdoor:vision", "【天气】"+day_phase[current_day_phase]["time_msg"] + "\n", users());

	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	control_shops(current_day_phase);
}

// 目前东西不多就这么处理，以后可以把这部分拿出去
// 单作一个起定时起作用的 daemon 进行这类事物的处
// 理，完全可以做到更精确的定时。

// 目前已经移出
protected void do_daily_affair()
{
	if(current_day_phase == 1) 	// 除掉遇强盗标记。
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
				// 为直观和编程人员易于理解，将数字转换成
				// begin_day 、begin_night 两个字符串传入。
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
		message("outdoor:vision", "【天气】"+current_weather_msg[weather_now(0)]["better"] + "。\n", users());
		return;

	}
	weather_flag = 1;
	weather_room_description = current_weather_msg[weather_now(p)]["look"];

	call_out("effect_to_users",2,p);  // 天气状况对玩家产生影响.

	if(flag == 1)
	{
	message("outdoor:vision", "【天气】"+current_weather_msg[weather_now(p+1)]["better"] + "。\n", users());
	call_out("update_weather",current_weather_msg[weather_now(p)]["length"],(p-1),1);
	}

	else
	{
	message("outdoor:vision", "【天气】"+current_weather_msg[weather_now(p)]["info"] + "。\n", users());

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
		current_season = 1;	// 春季
		// 季节的变更并不只限于户外，所以此message没有用outdoor，所有玩家都能看到季节信息。
		message("vision", "【 季 节 】春天到来了，天气开始转暖，大地逐渐呈现出一片勃勃生机。\n",users());
		if( !undefinedp( "spring_season" ) )
			call_other( this_object(), "spring_season" );
		break;
	case 126:
		weather_msg = summer_weather;
		current_season = 2;	// 夏季
		message("vision", "【 季 节 】炎热的夏季开始了，大地也开始变得躁动不安。\n",users());
		if( !undefinedp( "summer_season" ) )
			call_other( this_object(), "summer_season" );
		break;
	case 220:
		weather_msg = autumn_weather;
		current_season = 3;	// 秋季
		message("vision", "【 季 节 】金色的秋天开始了，到了收获自己辛勤耕耘的成果的时候了。\n",users());
		if( !undefinedp( "autumn_season" ) )
			call_other( this_object(), "autumn_season" );
		break;
	case 311:
		weather_msg = winter_weather;
		current_season = 4;	// 冬季
		message("vision", "【 季 节 】寒冬降临大地，北风开始呼啸着肆虐整个世界。\n",users());
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
		return "春风拂面";
		break;
	case 2:
		return "夏日倾诉";
		break;
	case 3:
		return "秋风送爽";
		break;
	case 4:
		return "白雪皑皑";
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
			tell_object(ob[i], "你觉得一阵晕眩，好像有一股能量从身上被人吸走了。\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "随著太阳升到天空的正中央，你觉得你的法力开始消失了。\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

// for 拦路抢劫。
void event_sunrise()
{
	object *ob;

	ob = filter_array(children("/std/room/npc/qiangdao_t"),(: clonep :));
	ob->do_remove();
}

string outdoor_room_description()
{
	if(weather_flag)
		return "    " + weather_room_description + "。\n";
	else return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
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
