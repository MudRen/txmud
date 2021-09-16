// louashu.c
// by ���ֺ�(Find).
// ���������

#define SHELL	"/d/phome/origin_objs/shell"

#include <ansi.h>
inherit NPC;

/* �ļ����ݵļ۸� 1. 300 gold 2. 600 gold 3. 900 gold 4.1300 gold*/
string *home_level_name = ({ "һ��é����","һ���߷�","һ��լԺ","������լԺ"});

void dest_objects();
void get_add_item(string arg,object me);
void add_domain(string arg,object me);
void add_level(string arg,object me);
private void get_month(string arg,object me,object *homes,int pay);
private void confirm_pay(string arg,object me,string *domains);

string want_build_home(object me);

void create()
{
	// ***** This object's name must be "banned". *****
	// I think the environment of this object may be set "no_fight".
	set_name("§����", ({ "lou ashu", "lou", "ashu" }));
	set("title", "��������");

	set("str", 20);
	set("gender", "����");
	set("age", 55);
	set("long",
"ֻ�������ļ���������ͷ��Ŀ����ֻС�۾�
�������⣬һ���Ͳ���һ���öԸ����ˡ�����
�����ڹ���Ϊ�٣������´�����Ե�ܺã�����
���˷��ݹ�������ʲ\n");

	set("combat_exp", 150);
	set("attitude", "friendly");
	set("inquiry", ([
	"����" : (: want_build_home :),
	"��" : (: want_build_home :),
]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
 
void init()
{
	object ob;

	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_mai",({"mai","buy"}));
	add_action("do_add",({"bujiao","add"}));
	add_action("do_pay","pay");
}

int do_mai(string arg)
{
	object ob,me = this_player();

	if(!is_day())
		return notify_fail(CYN"§����˵���������Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n"NOR);

	ob = new(SHELL);

        switch(player_pay(me, 5000/* 50 ������һ��*/))
	{
		case 0:
			return notify_fail("��⵰��һ�ߴ���ȥ��\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
                message_vision("$N��$n����������һ�Ž��������\n", me, this_object());
                ob->move(me);
        }
        return 1;
}

int accept_object(object who, object ob)
{
	int domain,home,level;

	if(!is_day())
	{
		command("say �����Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n");
		return 0;
	}

/*
	if(wizardp(who))
	{
		command("say ��ʦ���Ҷ�����ʲô��Ҫ���͸���Ȩ�ޡ�\n");
		return 0;
	}
*/

	if(!ob->is_build_home_shell())
	{
		if(ob->query("money_id"))
		{
			if(to_int(ob->value()) >= 1000)
			{
				command("say ����ȥ����¥��һ���ˣ���л����л��\n");
				dest_objects();
				return 1;
			}
			command("say Ҫ��¸��͢���٣����㲻����ˣ�\n");
			return 0;
		}
		if(who->query("gender") == "Ů��")
		{
			if(who->query("age") <= 30)
			{
				command("xixi");
				command("say ��λ�������Ҷ������ǲ��Ƕ�������˼�ˣ����Ҿ������ˡ�\n");
				dest_objects();
				return 1;
			}
			command("say ��ô��������Ů�ˣ�����ʲôҲû�á�\n");
			return 0;
		}
		command("say ʲô���߰���Ķ���Ҳ���������������ҳ�ȥ��\n");
		return 0;
	}

	if(!ob->query("player_id"))
	{
		command("say ����һ�ſձ���ʲô��\n");
		return 0;
	}

	if(ob->query("player_id") != who->query("id"))
	{
		command("say ���������ֻ�ܱ���������\n");
		return 0;
	}

	if(who->query("age") < 18)
	{
		command("say �㻹û�����أ������ܽ��Լ��ķ���\n");
		dest_objects();
		return 1;
	}
	
	domain = ob->query("domain_cost");
	level  = ob->query("home_level");
	home   = PLAYERHOME_D->home_value(level);

	if(!pay_from_bank(who,domain+home))
	{
		command("say �����д����������������Ժ���˵�ɡ�\n");
		return 1;
	}

	who->set("can_build_home/level",level);
	who->set("can_build_home/cost_home",home);
	who->set("can_build_home/cost_domain",domain);
	who->set("can_build_home/time",time());
	who->save();

	command("nod");
	command("say ������ö�ͨ�����л����ˣ���ȥ�����ɣ�����ָ��������޵ģ����˾�û�ˡ�\n");
	command("say ע�⣺����ʱ�䲻Ҫ����һ���¡�\n");
	dest_objects();
	return 1;
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;

	if(!is_day())
		return;

	switch(random(2))
	{
		case 0 :
			command("say ��λ"+RANK_D->query_respect(ob)+"���������к����飿\n");
			break;
		case 1 :
			command("say ����ֻ���������ˣ������������ذɡ�\n");
			break;
	}
}

string want_build_home(object me)
{
	if(!is_day())
		return "�����Ѿ�Ъ���ˣ�����˵㵽��ŵ�ǰ������\n";

	if(PLAYERHOME_D->user_have_home(me->query("id")))
	{
		command("shake");
		return "���ڵ�Ƥ���ţ�ÿ��ֻ�ܽ�һ��סլ��\n";
	}

	if(wizardp(me))
		return "��ʦ��������ʲô�ң����ҿ���վ��\n";

	if(me->query("age") < 18)
		return "��ʮ��������Ժ�������\n";

	return "Ҫ������?���õص�����?��(mai)һ�Ž��������(shell)��(tianxie)���˽����ҡ�\n";
}

void dest_objects()
{
	int i;
	object *inv;

	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id") == "cloth")
			continue;
		destruct(inv[i]);
	}
}

int do_add(string arg)
{
	object me = this_player();

	if(!mapp(me->query("can_build_home")))
		return notify_fail("��û�а������������������ʲô����ҳ�ȥ��\n");
	write("��������Ŀ��	1.��Ƥ��		2.���ۡ�\n");
	write("��ѡ��Ҫ�����ķ������ͣ�\n");
	input_to((: get_add_item :),me);
	return 1;
}

void get_add_item(string arg,object me)
{
	int level;

	switch (atoi(arg))
	{
		case(1):
			write("��Ҫ�����������ƽ�ĵ�Ƥ�ѣ�\n");
			input_to((: add_domain :),me);
			break;
		case(2):
			level = (int)me->query("can_build_home/level");
			if(level == 4)
			{
				write("�㽻�ķ����㹻�޽���߼���סլ�������ٲ��������ˡ�\n");
				return;
				break;
			}

			write(sprintf("���ѽ��ķ��ۿ����޽�%s��\n",home_level_name[level-1]));
	write(sprintf("  1. һ��é����(%s)          2. һ���߷�(%s)\n",
			"���ò���",
		(level>=2)?"���ò���":"�貹��"+to_int(( PLAYERHOME_D->home_value(2)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�" ));
	write(sprintf("  3. һ��լԺ(%s)            4. ������լԺ(%s)\n",
		(level>=3)?"���ò���":"�貹��"+to_int(( PLAYERHOME_D->home_value(3)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�",
		(level>=4)?"���ò���":"�貹��"+to_int((PLAYERHOME_D->home_value(4)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�", ));

			write("��ѡ����Ҫ����ķ������ͣ�\n");
			input_to((: add_level :),me);
			break;
		default:
			write("��������Ŀ��	1.��Ƥ��		2.���ۡ�\n");
			write("��ѡ��Ҫ�����ķ������ͣ�\n");
			input_to((: get_add_item :),me);
			return;
	}
}

void add_domain(string arg,object me)
{
	int fee;
	if(!atoi(arg))
	{
		write("��Ҫ�����������ƽ�ĵ�Ƥ�ѣ�\n");
		input_to((: add_domain :),me);
		return;
	}

	else
	{
		fee = to_int(atoi(arg)*gold_bvalue());
		if(!pay_from_bank(me,fee))
		{
			write("�����д������Ժ���˵�ɡ�\n");
			return;
		}

		me->add("can_build_home/cost_domain",fee);
		write("ok.\n");
		return;
	}
}

void add_level(string arg,object me)
{
	int level,fee;

	level = (int)me->query("can_build_home/level");

	if(!atoi(arg) || atoi(arg) <= level)
	{
		write(sprintf("���ѽ��ķ��ۿ����޽�%s��\n",home_level_name[level-1]));
		write(sprintf("  1. һ��é����(%s)          2. һ���߷�(%s)\n",
			"���ò���",
		(level>=2)?"���ò���":"�貹��"+to_int((PLAYERHOME_D->home_value(2)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�", ));
		write(sprintf("  3. һ��լԺ(%s)            4. ������լԺ(%s)\n",
		(level>=3)?"���ò���":"�貹��"+to_int((PLAYERHOME_D->home_value(3)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�",
		(level>=4)?"���ò���":"�貹��"+to_int((PLAYERHOME_D->home_value(4)-PLAYERHOME_D->home_value(level))/gold_bvalue())+"���ƽ�", ));

		write("��ѡ����Ҫ����ķ������ͣ�\n");
		input_to((: add_level :),me);
		return;
	}

	else
	{
		fee = PLAYERHOME_D->home_value(atoi(arg)) - PLAYERHOME_D->home_value(level);
		if(!pay_from_bank(me,fee))
		{
			write("�����д������Ժ���˵�ɡ�\n");
			return;
		}

		else
		{
			me->set("can_build_home/level",atoi(arg));
			write("ok.\n");
			return;
		}
	}
}

int do_pay(string arg)
{
	object me = this_player();
	int n,i,l,bk;
	string *rooms,*domains=({});

	if(! rooms = PLAYERHOME_D->user_have_home(me->query("id")))
		return notify_fail("��û���Լ��ķ��ݡ�������ȥ�������������ܾ�����\n");


	n = sizeof(rooms);
	for(i=0;i<n;i++)
	{
		string domain;
		if(sscanf(rooms[i],PHOME_DIR+"%s/%*s",domain))
			domains += ({ domain });
	}

	if((n=sizeof(domains)) == 1)
		confirm_pay("1",me,domains);

	else
	{
		string out = "";

		for(i=0;i<n;i++)
			if(strlen(domains[i]) > l)
				l = strlen(domains[i]);
		bk = to_int(60/(l+4));
		l++;
		for(i=0;i<n;i++)
			out += sprintf("%-2d.%-"+(string)l+"s%s",(i+1),domains[i],(i%bk==(bk-1))?"\n":"" );
		write("��������"+chinese_number(n)+"�������������Լ���סլ������ѡ��һ����\n"+out+"\n");
		input_to( (: confirm_pay :),me, domains );
	}

	return 1;
}

private void confirm_pay(string arg,object me,string *domains)
{
	object *homes,home;
	int pay,n;
	string file;

	if(arg[0] == 'q')
		return;

	n = atoi(arg);
	n--;
	if( (n<0) || (n>=sizeof(domains)) || !me)
		return;

	file = sprintf("%s%s/%s_home",PHOME_DIR,domains[n],me->query("id"));

	home = find_object(file);
	if(!home)
		home = load_object(file);
	if(!home)
	{
		write("���סլ�����⣬������ʦ�걨����\n");
		return;
	}

	homes = PLAYERHOME_D->player_homes(me,home);
	if( !homes || !arrayp(homes) || !sizeof(homes) )
	{
		write(sprintf("����%s��ס���������⣬����������ʦ���档\n",
			to_chinese(domains[n])));
		return;
	}

	pay = PLAYERHOME_D->home_value(homes[0]->home_level())/100; /* ÿ���µ����ɷ�Ϊ���۵� 1%. */

	write(sprintf("����ס��ÿ���µ����ɷ�Ϊ��%s\n",chinese_value(pay)));
	write("��Ҫ�����ٸ��µķ������ɷѣ�\n");
	input_to ((: get_month :),me,homes,pay);
	return;
}

private void get_month(string arg,object me,object *homes,int pay)
{
	int m,i;

	if(!me)
		return;

	if(arg[0] == 'q')
		return;

	if(!arg || !m = atoi(arg))
	{
		write("��Ҫ�����ٸ��µķ������ɷѣ�\n");
		input_to ((: get_month :),me,homes,pay);
		return;
	}

	write(sprintf("%s���µ����ɷ�һ��%s��\n",chinese_number(m),chinese_value(pay*m)));
	if(!i = player_pay(me,pay*m) || i == -2)
	{
		write("�����ϵ��ֿ������Ʊ���Ҳ�����\n");
		return;
	}

	for(i=0;i<sizeof(homes);i++)
	{
		homes[i]->add("built_time",m*43200 /* 43200 Ϊ MUD �е�һ����.*/);
		homes[i]->save();
	}

	command("say "+me->name()+"����"+chinese_number(m)+"���·������ɷ�������\n");
	return;
}