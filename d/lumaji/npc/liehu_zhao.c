// liehu_zhao.c
// ÿ��ֻ����һ����.
// by Find.

#include <ansi.h>
#define MAX		10
#define GET_RATE	20

inherit NPC;
inherit F_SAVE;

string ask_me(object who);
string query_save_file() { return __DIR__"liehu_zhao"; }

class items{
	int year;
	int month;
	int day;
	string request_liewu;
	string playerid;
	int payed;
}

class items *wild_requests = ({});

static mapping liewu = ([ "Ұɽ��":__DIR__"obj/shanji",
"���":__DIR__"obj/zhangzi",
"��¹":__DIR__"obj/milu",
"ɽ��":__DIR__"obj/shanhu", ]);

private string pay_request(object who,string name,int yufu);
string check_request(string id);

void create()
{
	set_name("����", ({ "old zhao", "zhao" }) );
	set("title","�Ի�");
	set("gender", "����" );
	set("age", 47);
	set("long", "��������һ�������������֣�����ÿ�δ��Ի�
���ջ��񣬶�����ʱ���ܴ�һЩ�����Ұ
�ޣ�������ô�򵽵�ȴ�����˵������һ
���Ի���Ҳ�Ǻ���ͷ�Եģ���������һЩ��
��Ұ������Ҳ���а취��������Ǯ�ɲ������
ѽ����������������ڡ����ԡ������顣 \n");

	restore();
	set("inquiry",([
	"����" : (: ask_me :),
]));
	set("chat_chance",10);
	set("chat_msg",({
	CYN"����˵��������ǰ�ҵ�������˵���Ի��ķ�����ڴ��Եĵط��ͷ����ϣ�������Ҳ���ܺͱ���˵����\n"NOR,
	CYN"����˵�������⸽����ɽ���в�������Ұ�ޣ����Ǻ��Ѵ򵽡���\n"NOR,
}));

	set("combat_exp", 20000);
	set("per", 30);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);

	setup();
	carry_object(__DIR__"obj/hupi")->wear();
}

void init()
{
	add_action("huan_qian","huan");
}

int huan_qian()
{
	int value;
	object who = this_player();

	value = who->query("liehu_zhao");

	if(!value)
		return notify_fail("����˵������û��ǷС��Ǯѽ��\n");

	if(!player_pay(who,value))
		return notify_fail(sprintf("����˵��������С��%s�������������ϴ���Ǯ������\n",
			chinese_value(value)));

	else
	{
		write("����˵����Ǯ�����ˣ��Ժ�����ʲô��Ҫ��������С�ġ�\n");
		who->delete("liehu_zhao");
		return 1;
	}
}

string ask_me(object who)
{
	int i,n,last_month;
	class items item;
	string id;
	int year,month,day;

	if(who->query("liehu_zhao"))
		return sprintf("�㻹Ƿ����%sû���أ�\n",chinese_value(who->query("liehu_zhao")));

	n = sizeof(wild_requests);
	id = who->query("id");

	if(n)
	{
		for(i=0;i<n;i++)
		{
			if(!wild_requests[i])
				continue;

			if(wild_requests[i]->playerid == id)
			{
				item = wild_requests[i];
				break;
			}
		}
	}

	if(!item)
		return "�⸽����ɽ���в�������Ұ�ޡ��Ҵ򵽹�Ұɽ��(shan ji)��
          ���(zhang zi)����¹(mi lu)��ɽ��(shan hu)����֪����
          ���ָ���Ȥ������˵(say)����������ͨ�����������Ҷ���
          �������ˣ���Ҫ��Ҫ�Ļ�����ȥ�ǿ�����\n";

	else
	{
		year = query_year();
		month = query_month();
		day = query_day_in_month();

		if(year > item->year)
			last_month = month + 12 - item->month;
		else
			last_month = month - (int)item->month;

		if(last_month < 0)
		{
			if( (day - item->day) < 7)
				return sprintf("�������Ǹ���С�Ĵ�%s����%s��%s���Ժ��������ʰɡ���\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));
			else
				return sprintf("������С�Ĵ�%s���»�û��һ�����أ���%s��%s���Ժ��������ʰɡ���\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));
		}

		else if(last_month == 0)
		{
			if(item->day > day)
				return sprintf("������С�Ĵ�%s���»�û��һ�����أ���%s��%s���Ժ��������ʰɡ���\n",
					item->request_liewu,chinese_number(item->month),chinese_number(item->day));

			else
			{
				wild_requests[i] = 0;
				wild_requests -= ({0});
				save();
				return pay_request(who,item->request_liewu,item->payed);
			}
		}

		else if(last_month == 1)
		{
			wild_requests[i] = 0;
			wild_requests -= ({0});
			save();

			if(item->day < day)
				return "����Ҫ��"+item->request_liewu+"�Ҹ������ˣ������ܲ���������Ż��ˣ�û�취С�ľ͸����ˡ���\n";

			else
				return pay_request(who,item->request_liewu,item->payed);
		}

		else
		{
			wild_requests[i] = 0;
			wild_requests -= ({0});
			save();
			return "����Ҫ��"+item->request_liewu+"�Ҹ������ˣ������ܲ���������Ż��ˣ�û�취С�ľ͸����ˡ���\n";
		}
	}
}

void relay_say(object ob, string arg)
{
	string req,what;

	if(!stringp(arg) || arg == "")
		return;

	if(strsrch(arg,"Ұɽ��") != -1 || strsrch(arg,"shan ji") != -1)
		req = "Ұɽ��";
	else if(strsrch(arg,"���") != -1 || strsrch(arg,"zhang zi") != -1)
		req = "���";
	else if(strsrch(arg,"��¹") != -1 || strsrch(arg,"mi lu") != -1)
		req = "��¹";
	else if(strsrch(arg,"ɽ��") != -1 || strsrch(arg,"shan hu") != -1)
		req = "ɽ��";

	if(!req)
		return;

	if(ob->query("liehu_zhao"))
	{
		write(sprintf("�㻹Ƿ����%sû���أ�\n",chinese_value(ob->query("liehu_zhao"))));
		return;
	}

	if(sizeof(wild_requests) >= MAX)
	{
		write(CYN"����˵����ʵ�ڱ�Ǹ��С������ӵĻ�̫���ˣ�����һ��ʱ�����������ɡ�\n"NOR);
		return;
	}

	what = check_request(ob->query("id"));
	if(what)
	{
		write(CYN"����˵�����������Ѿ��и�С��ȥ��"+what+"����������ʱ���������ʰɡ�\n"NOR);
		return;
	}

	ob->set_temp("liehu_zhao/request",req);
	write(CYN"����˵������"+req+"�ⶫ���ܲ��ô����ø���һ���µ�ʱ�䡣������Ҫ�ȸ�ʮ�����ӵĶ���
          ������˾ʹӼ۸�����ȥ��ʮ�������û�򵽾������͸�С�ĵ�����Ǯ�ˡ���\n"NOR);

	return;
}

int accept_object(object me,object obj)
{
	string req;
	int year,month,day,flag;
	class items item;

	if(!is_money(obj))
		return 0;

	if(!req = me->query_temp("liehu_zhao/request"))
		return notify_fail(CYN"����˵�������޹�����»��С������ƽ���޹ʽ�������Ǯ����\n"NOR);

	if(obj->value() < 1000)
		return notify_fail(CYN"����˵��������"+req+"����ҲҪ�������ӵĶ��𡣡�\n"NOR);

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	month++;

	if(month > 12)
	{
		month -= 12;
		year++;
		flag = 1;
	}

	item = new(class items);
	item->year = year;
	item->month = month;
	item->day = day;
	item->request_liewu = req;
	item->playerid = me->query("id");
	item->payed = (int)obj->value();

	wild_requests += ({ item });
	save();

	write(sprintf(CYN+"���Կ��˿�����˵�������ðɣ��ҽ���һ���µ�ʱ�����������%s��%s���Ժ������ҽ����
                      ������ˣ�С��մ���Ĺ�Ҳ��׬һ�ȣ����ʵ�ڴ򲻵���Ҳ����ҡ�
                      ���ˣ�����ǧ��𳬹�2���£��������˷Ų�������Ҫû����ֻ�ô�
                      ��������ˡ���\n"+NOR,(flag)?"����"+chinese_number(month):chinese_number(month),chinese_number(day)));

	me->delete_temp("liehu_zhao/request");
	return 1;
}

void refresh_requests()
{
	int i,n,year,month,day,last_month;

	if(!n = sizeof(wild_requests))
		return;

	year = query_year();
	month = query_month();
	day = query_day_in_month();

	for(i=0;i<n;i++)
	{
		if(year > wild_requests[i]->year)
			last_month = month + 12 - wild_requests[i]->month;
		else
			last_month = month - wild_requests[i]->month;

		if(last_month == 2)
		{
			if(day >= wild_requests[i]->day)
				wild_requests[i] = 0;
		}

		else if(last_month > 2)
			wild_requests[i] = 0;
	}

	wild_requests -= ({0});
	save();
}

private string pay_request(object who,string name,int yufu)
{
	int value,flag;
	object ob;
	string msg;

	if(random(100) > GET_RATE)
		return "��ʵ�ڱ�Ǹ��С��������춼���ң�������Ӱ��Ҳû��������
          ���ٿ�������Ҫʲô��İɣ�С��һ��������������";

	else
	{
		write(CYN"����˵��������Ҫ��"+name+"�������ˣ��������С�Ĳ�����������\n");
		ob = new(liewu[name]);
		value = ob->query("value")/10*4;

		if(!ob->move(who))
		{
			flag = 1;
			ob->move(environment());
		}

		write(sprintf("���ԴӺ����ϳ�һֻ%s%s��\n",ob->name(),flag?"":"������"));
		if(value <= yufu)
			return "�������ҵ�Ԥ�����Ѿ��ܶ��ˣ���"+ob->name()+"����С��Т�������ˡ�\n";

		msg = sprintf("��%s����%s����ȥ����Ԥ����%s����ֻҪ�ٸ�����%s�����ˡ�\n",
			ob->name(),chinese_value(value),chinese_value(yufu),chinese_value(value-yufu));
		value -= yufu;
		if(!player_pay(who,value-yufu))
		{
			
			who->set("liehu_zhao",(int)value);
			msg += "�������ϵ�Ǯ���Ĳ������»���·�������ٻ�(huan)�Ҿ����ˡ�\n";
		}
		else
			msg += "Ǯ�����ˣ��»�����ʲô��Ҫ�������ҡ�";

		return msg;
	}
}

string check_request(string id)
{
	int i,n;

	n = sizeof(wild_requests);
	if(!n) return 0;
	for(i=0;i<n;i++)
	{
		if(wild_requests[i]->playerid == id)
			return wild_requests[i]->request_liewu;
	}

	return 0;
}