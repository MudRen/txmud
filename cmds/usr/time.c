// time.c
// by ���ֺ�(Find).  (11/98)

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
		write("�뱨����ʦ natured ���� bug.\n");
		return 1;
	}

	d_flag = is_day();
	weather = weather_now();
	degree = weather_degree();

	if(!d_flag || (weather == "clear"))
		out_w = "��";
	else
	switch (season)
	{
		case 1:	// ����
		case 3:	// �＾
			if(weather == "wind")
				out_w = "�η�";
			else if(weather == "fog")
				out_w = "��";
			else
				out_w = (degree == "finish")?"����":"��";
			break;
		case 2:	// �ļ�
			if(weather == "wind")
				out_w = (degree == "finish")?"�η�":"����";
			else
				out_w = (degree == "finish")?"��":"����";
			break;
		case 4: // ����
			if(weather == "wind")
				out_w = "�η�";
			else
				out_w = (degree == "begain")?"��":"��ѩ";
			break;
		default:
			return notify_fail("���ִ���\n");;
			
	}

	out = sprintf("\nʱ�䣺%s����%s��%s��%s�� [%s]\n       %sʱ%s�� [%s] [%s]\n\n",
		MUD_NAME,
		((year == 0)? "Ԫ":chinese_number(year)),
		chinese_number(month),
		chinese_number(day),
		chinese_season(season),
		chinese_number(hour),
		chinese_number(minute),
		d_flag?"��":"ҹ",
		out_w
);
	write(out);
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: time

���ָ������֪��������Ϸ�е�ʱ����

HELP
    );
    return 1;
}
