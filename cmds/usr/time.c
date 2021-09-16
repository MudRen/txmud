// time.c
// by 发现号(Find).  (11/98)

inherit F_NATURE;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int year,month,day,time;
	int season,hour,minute,d_flag;
	string out,weather,degree,out_w;

	year = NATURE_D->query_year();
	time = NATURE_D->query_current_time();
	season = NATURE_D->query_season();

	hour = time / 60;
	minute = time - hour * 60;

	if ( sscanf( NATURE_D->query_month(),"month %d:day %d",month,day) != 2)
	{
		write("请报告巫师 natured 出现 bug.\n");
		return 1;
	}

	d_flag = is_day();
	weather = weather_now();
	degree = weather_degree();

	if(!d_flag || (weather == "clear"))
		out_w = "晴";
	else
	switch (season)
	{
		case 1:	// 春季
		case 3:	// 秋季
			if(weather == "wind")
				out_w = "刮风";
			else if(weather == "fog")
				out_w = "雾";
			else
				out_w = (degree == "finish")?"下雨":"云";
			break;
		case 2:	// 夏季
			if(weather == "wind")
				out_w = (degree == "finish")?"刮风":"下雨";
			else
				out_w = (degree == "finish")?"云":"下雨";
			break;
		case 4: // 冬季
			if(weather == "wind")
				out_w = "刮风";
			else
				out_w = (degree == "begain")?"云":"下雪";
			break;
		default:
			return notify_fail("出现错误。\n");;
			
	}

	out = sprintf("\n时间：%s创世%s年%s月%s日 [%s]\n       %s时%s分 [%s] [%s]\n\n",
		MUD_NAME,
		((year == 0)? "元":chinese_number(year)),
		chinese_number(month),
		chinese_number(day),
		chinese_season(season),
		chinese_number(hour),
		chinese_number(minute),
		d_flag?"日":"夜",
		out_w
);
	write(out);
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

这个指令让你知道现在游戏中的时辰。

HELP
    );
    return 1;
}
