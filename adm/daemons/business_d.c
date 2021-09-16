// /adm/daemons/business_d.c
// by Find.

#define ETC_FILE	"/adm/etc/busi_domains"
#define WROOM(x)	sprintf("/d/%s/business",x)
// ��С������ 5000 ���ƽ𣬼���50��������
#define MIN_CHANGE	5000

#define MAX_ARRIVE	1	/* 1�� */
#define MIN_ARRIVE	60	/* 60 �� */

#include <price.h>

class coordinate{ int x; int y; }

private mapping valid_domains = ([]);
private void init_domains();
private void random_change(object room,int flag);
private mapping all_ids = ([]);
private void init_all_wares();
private string *changed_domain = ({});

void create()
{
	seteuid(getuid());
	init_domains();
	init_all_wares();
}

private void init_domains()
{
	string *domains;
	class coordinate position;
	int i,n;

	if(file_size(ETC_FILE) <= 0)
	{
		log_file("business",sprintf("BUSINESS_D: ETC_FILE no exits or havn't content.%s\n",
			ctime(time())));
		return;
	}

	domains =  filter_array(explode(read_file(ETC_FILE), "\n") - ({ "" }), (: $1[0] != '#' :));
	if(!n = sizeof(domains))
	{
		log_file("business",sprintf("BUSINESS_D: Have not valid domains. %s\n",
			ctime(time())));
		return;
	}

	for(i=0;i<n;i++)
	{
		string domain,temp;
		int x,y;

		position = new(class coordinate);

		if(sscanf(domains[i],"%s %s",domain,temp) != 2)
		{
			log_file("business",sprintf("BUSINESS_D: ͨ���� %s �������\n",
				domains[i]));
			continue;
		}

		if(sscanf(temp,"%d,%d",x,y) != 2)
		{
			log_file("business",sprintf("BUSINESS_D: ͨ���� %s �������\n",
				domains[i]));
			continue;
		}

		position->x = x; position->y = y;
		valid_domains += ([ domain : position ]);
	}

	log_file("business",sprintf("BUSINESS_D: Start up success at %s.\n",
		ctime(time())));
}

string *query_valid_domains()
{
	return keys(valid_domains);
}

// ������أ�1Сʱ��Ѳһ�Ρ�
void random_check()
{
	int max,min,i,n,a,flag;
	object max_room,min_room,*rooms = ({});
	string *domains;

	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID))
		return;

	domains = keys(valid_domains);

	n = sizeof(domains);

	if(sizeof(changed_domain) >= n)
		changed_domain = ({});

	for(i=0;i<n;i++)
	{
		object room;
		string file = WROOM(domains[i]);
		int rate;

		if(file_size(file+".c") <= 0)
			continue;
		room = find_object(file);
		if(!room)
			room = load_object(file);
		if(!room)
			continue;

		// recover
		if(!flag && (member_array(domains[i],changed_domain) == -1) )
		{
			changed_domain += ({ domains[i] });
			flag = 1;
			log_file("business",sprintf("SYSTEM: Start recover .%s.\n",domains[i]));
			room->random_recover();
		}

		rate = room->query_price_rate();
		if(max < rate)
		{
			max = rate;
			max_room = room;
		}
		else if(min > rate)
		{
			min = rate;
			min_room = room;
		}
		else
			rooms += ({ room });
	}

	a = random(100);

	if(a < 20)	// ������Сֵ
	{
		if(objectp(min_room))
			random_change(min_room,1);
	}

	else if(a < 40)	// �������
	{
		if(sizeof(rooms))
			random_change(rooms[random(sizeof(rooms))],0);
	}

	else if(a < 60)	// �������ֵ
	{
		if(objectp(max_room))
			random_change(max_room,1);
	}
}

// flag = 1 �ָ�����; flag = 0 �������
private void random_change(object room,int flag)
{
	int dir,rate,times;

	rate = room->query_price_rate();

	if(flag && (rate != 100))	// �ָ�����
	{
		times = abs(100 - rate)/10;
		if(times < 1)
			times = 1;
		if( rate < 100 )
			dir = 1;	// ����
		else
			dir = -1;	// ��С��
	}

	else	// �������
	{
		if(random(2))
			dir = 1;
		else
			dir = -1;

		if(!random(10)) // �д���
			times = 2;
		else
			times = 1;
	}

	room->random_change( dir*times*MIN_CHANGE );
}

int
count_fasong_time(
	string now,	/* ���ﵱǰ���ڵ� */
	string dest,	/* Ŀ�ĵ� */
	int value	/* ������ֵ(��λ gold) */
	)
{
	class coordinate nowp,destp;
	int time;

	if( (member_array(now,query_valid_domains()) == -1)
	|| (member_array(dest,query_valid_domains()) == -1) )
		return 0;

	nowp = valid_domains[now];
	destp = valid_domains[dest];

	time = (abs(nowp->x - destp->x) + abs(nowp->y - destp->y))/5;

	if(time < 1)
		time = 1;

	return time;
}

private void init_all_wares()
{
	string *items,kind;
	int i,n;

	items =  filter_array(explode(PRICES, "\n") - ({ "" }), (: $1[0] != '#' :));

	if(!items || !(n=sizeof(items)))
		return;

	for(i=0;i<n;i++)
	{
		string name,id,unit;
		int value;

		if(sscanf(items[i],"%s %s %s %d",name,id,unit,value) == 4)
			all_ids[kind] += ({ id });

		else
		{
			kind = items[i];
			all_ids[kind] = ({});
		}
	}
}

string query_ware_class(string ware_id)
{
	string out,*cls;
	int i,n;

	if(!stringp(ware_id) || !sizeof(all_ids))
		return 0;

	if(!n = sizeof(all_ids))
		return 0;

	cls = keys(all_ids);

	for(i=0;i<n;i++)
		if(member_array(ware_id,all_ids[cls[i]]) != -1)
		{
			out = cls[i];
			break;
		}

	return out;
}
