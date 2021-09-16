// /adm/daemons/cron_d.c
// by Find.

#pragma optimize

#define CRONTAB		"/adm/etc/crontab"
#define INTERVAL	60

inherit F_NATURE;

protected int ready = 0;
protected void init_crontab();
protected int *setup_item(string str);

class cron_item
{
	int flag;		// flag 0 现实生活; flag 1 游戏中
	int *day_in_month;	// 每月几号
	int *day_in_week;	// 一星期中的第几天
	int *month_in_year;	// 每年中的第几月
	int *hour;		// 每天中的第几小时
	int *minute;		// 每小时中的第几分
	string file;		// 触发物件的文件名
	string func;		// 触发函数
}

class cron_item *all_items = ({});
protected void out(string str)
{
	log_file("cron",str);
}

void create()
{
	seteuid(getuid());
	init_crontab();
	call_out("continue_scan",INTERVAL);
}

protected void init_crontab()
{
	string *items;
	int i,n;

	if(file_size(CRONTAB) < 0)
		return;
	items =  filter_array(explode(read_file(CRONTAB), "\n") - ({ "" }), (: $1[0] != '#' :));

	if(!n=sizeof(items))
		return;

	for(i=0;i<n;i++)
	{
		string *table,*time_zone;
		class cron_item item;
		int flag,legal = 0;
		object ob;

		reset_eval_cost();
		table = explode(items[i]," ");
		if(sizeof(table) < 3) // table 不完整。
		{
			out(sprintf("以下任务格式错误：\n%s\n\n",items[i]));
			continue;
		}
		time_zone = explode(table[0],":");
		if(sizeof(time_zone) < 6)	// time_zone 不完整。
		{
			out(sprintf("以下任务时间部分格式错误：\n%s\n\n",items[i]));
			continue;
		}

		if(file_size(table[1]+".c") < 0)
		{
			out(sprintf("以下任务触发物件档案不存在：\n%s\n\n",items[i]));
			continue;
		}
		if(!ob = find_object(table[1]))
			ob = load_object(table[1]);
		if(!ob)
		{
			out(sprintf("以下任务触发物件无法载入：\n%s\n\n",items[i]));
			continue;
		}
		if(!function_exists(table[2],ob))
		{
			out(sprintf("以下任务触发物件中触发函数不存在：\n%s\n\n",items[i]));
			continue;
		}

		item = new(class cron_item);

		item->file = table[1];
		item->func = table[2];
		if(sscanf(time_zone[0],"%d",flag))	// flag
		{
			if( (flag != 0) && (flag != 1) )
			{
				out(sprintf("以下任务 flag 格式错误：\n%s\n\n",items[i]));
				continue;
			}

			item->flag = flag;
		}
		else
		{
			out(sprintf("以下任务 flag 格式错误：\n%s\n\n",items[i]));
			continue;
		}

		// day_in_month
		if( !(item->day_in_month = setup_item(time_zone[1])) )
		{
			out(sprintf("以下任务 day_in_month 格式错误：\n%s\n\n",items[i]));
			continue;
		}
		if(sizeof(item->day_in_month))
			legal++;

		// day_in_week
		if( !(item->day_in_week = setup_item(time_zone[2])) )
		{
			out(sprintf("以下任务 day_in_week 格式错误：\n%s\n\n",items[i]));
			continue;
		}
		if(sizeof(item->day_in_week))
			legal++;

		// month_in_year
		if( !(item->month_in_year = setup_item(time_zone[3])) )
		{
			out(sprintf("以下任务 month_in_year 格式错误：\n%s\n\n",items[i]));
			continue;
		}
		if(sizeof(item->month_in_year))
			legal++;

		// hour
		if( !(item->hour = setup_item(time_zone[4])) )
		{
			out(sprintf("以下任务 hour 格式错误：\n%s\n\n",items[i]));
			continue;
		}
		if(sizeof(item->hour))
			legal++;

		// minute
		if( !(item->minute = setup_item(time_zone[5])) )
		{
			out(sprintf("以下任务 minute 格式错误：\n%s\n\n",items[i]));
			continue;
		}
		if(sizeof(item->minute))
			legal++;
		if( !legal )
		{
			out(sprintf("以下任务没有明确的触发条件：\n%s\n\n",items[i]));
			continue;
		}

		all_items += ({ item });
	}

	if(sizeof(all_items))
		ready = 1;
}

protected int *setup_item(string str)
{
	int *item = ({});
	string *bk;
	int n,i,num;

	if(!stringp(str) || str == "")
		return 0;

	if(str == "*")
		return item;

	if(strsrch(str,",") == -1)
	{
		if(!sscanf(str,"%d",num))
			return 0;
		item += ({ num });
		return item;
	}
	else
	{
		bk = explode(str,",");
		n=sizeof(bk);
		for(i=0;i<n;i++)
		{
			if(!sscanf(bk[i],"%d",num))
				return 0;
			item += ({ num });
		}
		return item;
	}
}

protected void continue_scan()
{
	int dinm,week,mon,h,min;
	int g_dinm,g_mon,g_h;
	// 游戏中不需要'星期'的概念。1分钟为现实生活1秒，所以最小定时单位为小时。
	mixed *local = localtime(time());
	int n,i;

	remove_call_out("continue_scan");
	call_out("continue_scan",INTERVAL);
	if(!ready)
		return;

	if(!n=sizeof(all_items))
		return;

	dinm = local[3];
	week = local[6];
	mon = local[4];
	h = local[2];
	min = local[1];

	g_dinm = query_day_in_month();
	g_mon = query_month();
	g_h = query_time()/60;

	for(i=0;i<n;i++)
	{
		object ob;
		//reset_eval_cost();
		if(all_items[i]->flag)	// 游戏时间
		{
			if(sizeof(all_items[i]->hour)
			&& (member_array(g_h,all_items[i]->hour) == -1) )
				continue;
			if(sizeof(all_items[i]->day_in_month)
			&& (member_array(g_dinm,all_items[i]->day_in_month) == -1) )
				continue;
			if(sizeof(all_items[i]->month_in_year)
			&& (member_array(g_mon,all_items[i]->month_in_year) == -1) )
				continue;

			ob = find_object(all_items[i]->file);
			if(!ob)
				ob = load_object(all_items[i]->file);
			if(!ob)
				continue;
			call_other(ob,all_items[i]->func);
		}
		else	// 现实时间。
		{
			if(sizeof(all_items[i]->minute)
			&& (member_array(min,all_items[i]->minute) == -1) )
				continue;
			if(sizeof(all_items[i]->hour)
			&& (member_array(h,all_items[i]->hour) == -1) )
				continue;
			if(sizeof(all_items[i]->day_in_week)
			&& (member_array(week,all_items[i]->day_in_week) == -1) )
				continue;
			if(sizeof(all_items[i]->day_in_month)
			&& (member_array(dinm,all_items[i]->day_in_month) == -1) )
				continue;
			if(sizeof(all_items[i]->month_in_year)
			&& (member_array(mon,all_items[i]->month_in_year) == -1) )
				continue;

			ob = find_object(all_items[i]->file);
			if(!ob)
				ob = load_object(all_items[i]->file);
			if(!ob)
				continue;
			call_other(ob,all_items[i]->func);
		}
                out(sprintf("%s\n%s->%s() 被执行。\n\n",
                        ctime(time()),
			all_items[i]->file,all_items[i]->func));
	}
}
