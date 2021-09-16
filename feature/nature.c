// nature.c
// by Find.
// �����Ա�׼ room �� npc ���Ѿ��̳У�
// �����̿���ֱ��������Щ������

// ����������ص�ǰ��Ϸ�������.
int query_year()
{
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	return ob->query_year();
}

/* ����������ص�ǰ��Ϸ�ļ���.
 * ����ֵ "1" : ����.
 * ����ֵ "2" : �ļ�.
 * ����ֵ "3" : �＾.
 * ����ֵ "4" : ����.
 */
int query_season()
{
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	return ob->query_season();
}

// ����������ص�ǰ��Ϸ���·���(1 - 12).
int query_month()
{
	int month,day;
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	sscanf( NATURE_D->query_month(),"month %d:day %d",month,day);

	return month;
}

// ����������������Ǵ����еĵڼ��졣
int query_day_in_month()
{
	int month,day;
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	sscanf( NATURE_D->query_month(),"month %d:day %d",month,day);

	return day;
}

// ����������ص�ǰ����һ���еĵڼ���(1 - 365).
int query_day(int *month_day)
{
	object ob = find_object(NATURE_D);

	if(!ob)	error("error: Can't find NATURE_D.\n");

	return ob->query_day(month_day);
}

// ����������ص�ǰ������״��.
// Ŀǰ��״����: clear ��,snow ѩ,wind ��,fog ��,cloudy ��,
// cloudy ��չ����������.
string weather_now()
{
	string effect,degree;

	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	sscanf( ob->query_weather(),"%s %s",effect,degree);

	return effect;
}

// ����������ص�ǰ������״����չ�ĳ̶�.
// "begain" : �ոտ�ʼ,������.
// "last"   : ��ʼ������.
// "finish" : �ǳ�����,��Ҳ��չ�������.
// ���� "cloudy" �����չ�� "finish" ��Ҫ������.
// "clear" �ĳ̶�û������.�ͷ���һ�� "now".
// �������Ҫ����Ч����Ҫ��ȷ�Ĳɼ�����ǰ������״��.
// ����Ҫ���״�����̶Ⱥͼ����ۺϵ��жϡ�
string weather_degree()
{
	string effect,degree;

	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	sscanf( ob->query_weather(),"%s %s",effect,degree);

	return degree;

}

// ��������ж�Ŀǰ�ǰ��컹�Ǻ�ҹ.
// ����ֵΪ "1" : ����.
// ����ֵΪ "0" : ��ҹ.
int is_day()
{
        string day_night;
        int time;
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	sscanf( ob->day_or_night(),"%s %d",day_night,time);

	return (day_night == "day");
}

// �������������ҹ�����һЩ��ϸ��Ϣ.
// ����ֵ��һ���ִ�,��ʽΪ: "day_or_night last_time".
// day_or_night Ϊһ���ִ�,ֵΪ "day" ���� "night" ��
// ӳĿǰ�ǰ��컹�Ǻ�ҹ.
// last_time ��һ�� int,��ӳ���Ǿ�����ҹ������ʣ��ʱ��.
// ���緵��ֵ "day 280" ˵��Ŀǰ�ǰ���,����ҹ����280��.
// �м���һ���ո����.
string day_night()
{
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	return ob->day_or_night();
}

// �����������ĿǰΪһ���еĵڼ�����.
int query_time()
{
	object ob = find_object(NATURE_D);

	if(!ob)	write("error: Can't find NATURE_D.\n");

	return ob->query_current_time();
}