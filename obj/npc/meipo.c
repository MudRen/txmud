// meipo.c
// by Find.

#undef DEBUG

#include <ansi.h>

inherit NPC;

int is_marry_ob() { return 1; }

private int minm = 20,minf = 18,chk_flag,wait;
private object master,working;

private string *msg = ({
"$FNAMEѽ������һ��������Ҫ�������أ���Ը������",
"������������˶�������һ�����춯�صĴ������㻹��֪���ɣ���",
"ǰһ��ʱ�佭���ϳ�����һλ����ʿ����λ��
               ��ʿһ������նɱ�����廢�����˺ڷ�կ������
               һʱ������ȵ������Զ�����ϱ�ѽ��",
"�����϶��ڷ׷ײ²���λ����ʿ��ʦ����������
              ����ǰ����˵����СС���꼶�书��ǿ��Ϊ����
              �����壬�������������������ֵ����������
              ��󱲶������Ϊʦ�أ�",
"�ݴ�˵�������ڲ�������������������ʿ�����ڹ����书����",
"����������Ʈ�������������޷�׽����",
"����˾ͽУ�$MNAME�����ڽ�����һ��
              �� $MNAME ����ͷ������������ʿ�޲�
              ����Ĵָ��а���޲��ŷ�ɥ���ģ�",
"������˵�����ϲ�����Ů���ڴ������أ�����
              �����Ĳ��ѣ����������޶����ԡ�",
"$FNAMEѽ��˵���⣬�ҿ�������������㱨ϲ��������",
"ǰ����$FM�����ҵ��ң���˵����$FNAMEŮ
              ���ķ�����ԸȢ��Ϊ�ޣ������������أ���",
"�ⲻ��������ϲ�£���������͸����ϲ����
              ��һ�¡�������֪��Ҫ�򷭶��ٴ�̳����������
              ���߽����ɾ�Ҫ���С���ˣ�",
"���������Ժ����� $FM���� ˫��˫�ɣ�����Ҳ
              û���е������鷳�����Ժ���Ҹ����ӿ��ǹ�Ҳ
              ���������� ���������Ĺ���Ҳֻ����Ľ��ҹ��
              �Լ��������ˡ�����",
"��һ����������Ĵ�ϲ��ѽ�����ⲻ��ͣ��ľ�
              ����������ϲ��������������֪��������ǲ�����
              ˼���ڵģ���ֻҪ���ͷ�����¾Ͱ����������ˣ�
              ����������⣡",
}),

*yes_msg = ({
"��",
"��",
"�õ�",
"�ð�",
"ͬ��","��ͬ��","Ը��","��Ը��",
}),

*shy_msg = ({
"����ʲô������˼�ģ�ֻҪ���ͷ�����һ�䣬ֻҪ�������׾����ˡ�",
"Ҫ������ҡͷ�����ͷ�㡣",
"���ֹؼ�ʱ�̿��Ǻ��߲���ѽ��",
"�׻�˵�ĺã������޼۱����ѵ������ˡ�",
"$FM�����ǳ��࣬�����ʣ�Ҫ���˻�ʮ������Ҫ������һ���أ���������",
"������Ҫ��һζ���ߣ�ʧ֮���ۿ���Ҫ�ź�����ѽ��",
"$FM��������һ��һ��������ǡ�",
});

varargs void fail(string msg)
{
	if(objectp(master) && stringp(msg))
		command(sprintf("tell %s %s",master->query("id"),msg));

	master = 0; working = 0;
}

private void go_home()
{
	object home = find_object(query("startroom")),env;

	if(!home)
		home = load_object(query("startroom"));
	if(!home)
	{
		destruct(this_object());
		return;
	}

	env = environment();

	if(env != home)
	{
		if(env)
			message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());

		move(home);
			message_vision("$N�Ҵ�ææ�����˽�����\n",this_object());
	}

	fail("�˼ҹ���˵ʲôҲ��Ը�⣬�����������㻹Ҫ��Ŭ��ѽ�������ҿ��Ժ���˵�ɡ�\n");
}

private int valid_status()
{
	object env;

	if(objectp(working))
		return 0;

	if( !(env=environment())
	|| (base_name(env) != query("startroom")) )
		return 0;

	return 1;
}

string ask_mei(object usr);

void create()
{
	set_name("ý��", ({"mei po"}));
	set("long", "����һλ��ʮ��������긾Ů������΢ʩ
���죬��˵������ƣ�ȴҲ�����̴档��
�����촽�������˫�ۿ��ó���һλ��˵
����Ľ�ɫ��\n");

	set("gender","Ů��");

	set("title",HIM"�������"NOR);

	set("age",35);
	set("con",20);
	set("per",25);

	set(NO_KILL, 1);
	set("no_return_home",1);

	set("inquiry",([
	"˵ý" : (: ask_mei :),
]));

	set("combat_exp",1500);

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
}

string ask_mei(object usr)
{
	if(!objectp(usr) || !userp(usr))
		return 0;

#ifndef DEBUG
	if(wizardp(usr))
		return "��ʦ�������顣\n";
#endif

	if(!valid_status())
		return "���ȵ�һ�°ɣ�������æ���ء�\n";

	if(usr->query("gender") == "Ů��")
	{
		if(usr->query("age") < minf)
			return "��ôС���������ż�����������������˵�ɡ�\n";
		return "����Ů������Ȣ�Լ��ģ��ҵ����������ý�Ż�û��Ů����ȥ˵��ý�ء�\n";
	}

	if(usr->query("age") < minm)
		return "СС����;��ż�Ȣ����������������˵�ɡ�\n";

        if(usr->query("is_bonze"))
                return "�������������ˣ�������\n";

	if(usr->query("marry/id"))
		return "��ôȢ�����Ż�Ҫ���ң�Ȣ���Ҫ��͢��׼�ģ�Ҫ���ҿ��ǲ��Ҹɡ�";

	usr->set_temp("mei_po/ask",1);
	return "����Ǵ��£������ļҹ����˸���(say)�ң�����˵�ɡ�\n";
}

void relay_say(object who,string arg)
{
	int n;
	object ob;

	if(!stringp(arg) || arg == "")
		return;

#ifndef DEBUG
	if(wizardp(who))
		return;
#endif

	if(chk_flag && (who == working))
	{
		if(member_array(arg,yes_msg) != -1)
		{
			chk_flag = 0;
			call_out("do_success",2);
		}
		return;
	}

	if(!valid_status() || !who->query_temp("mei_po/ask"))
		return;

	n = strlen(arg);

	if((n < 3) || (n > 10))
		return;

	for(int i=0;i<n;i++)
		if( (arg[i] < 'a') || (arg[i] > 'z') )
			return;

	if(objectp(working))
		command("say ���ȵ�һ�°ɣ�������æ���ء�\n");

	if( !objectp(ob = find_player(arg)) || !environment(ob))
	{
		command("say ���ں���û������ˣ����Һ�����˵�ɡ�\n");
		who->delete_temp("mei_po");
		return;
	}

	if(ob->query("gender") == "����")
	{
		command("say �ǿ��Ǹ�����ѽ�����������ˣ������������Լ�ȥ��ɣ�\n");
		who->delete_temp("mei_po");
		return;
	}

#ifndef DEBUG
	if(wizardp(ob))
	{
		command("say ����涨���������ʦ��顣\n");
		return;
	}
#endif

	if(ob->query("age") < minf)
	{
		command("say ���۹��治�����Ů�ҿ��ⶼϲ������������̫С�ˣ��������ĵȼ���ɡ�\n");
		who->delete_temp("mei_po");
		return;
	}

	if(mapp(ob->query("marry")))
	{
		command("say �˼ҿ����з�֮������͵�������������Լ���취�ɡ�\n");
		who->delete_temp("mei_po");
		return;
	}

	if( base_name(environment(ob)) == PRISON_OB )
	{
		command("say �üһ������������أ��ҿɲ������ǣ�\n");
		return;
	}

	command(sprintf("say ��ѽ��%s����￴��������ϲ���������۹����ǲ���
	��������������һ�ԡ������һ˫������ý������������
	�������������еľͿ����ƻ����������Ǯ�����ô���
	��������Ǯ�ɣ���ô�õ����������ͳ��������ƽ�ɡ�
",ob->name()));
	who->set_temp("mei_po/want",arg);
}

int accept_object(object me, object ob)
{
	if(!me || !me->query_temp("mei_po/want"))
		return 0;

#ifndef DEBUG
	if(wizardp(me))
		return 0;
#endif

	if(!valid_status())
	{
		command("say ���ȵ�һ�°ɣ�������æ���ء�\n");
		return 0;
	}

	if( !objectp(working = find_player(me->query_temp("mei_po/want"))) )
	{
		command("say ������������Ѿ����ˣ��Ժ���˵�ɡ�");
		me->delete_temp("mei_po");
		working = 0;
		return 0;
	}

	if(!is_money(ob) || ob->value() < 50000)
	{
		command("say Ϊ�������Ҹ����������Ӷ����ϳ�ѽ������\n");
		working = 0;
		return 0;
	}

	if(environment(ob) == environment())
		command(sprintf("say л�����ͣ�%s����˵Ȼ��������͸���˵��\n",me->name()[0..1]));
	else
		command(sprintf("say л�����ͣ�%s���������Ȼ���������ȥ����˵ýȥ��\n",me->name()[0..1]));

	master = me;
	me->delete_temp("mei_po");
	call_out("go_to",3);
	return 1;
}

private void go_to()
{
	if(!working)
	{
		fail("�㿴�ϵĹ����Ѿ����ˣ�ֻ���Ժ���˵�ˣ��ļ��Բ����ȶ�����Ҳ��̫�ż���");
		return;
	}

	if(environment(working) == environment())
	{
		tell_room(environment(),sprintf("\n%s��%s����һ��˵�������Ļ���\n\n",
			name(),working->name()),({working,this_object()}));

		tell_object(working,sprintf("\n%s�յ����ǰ�����صĳ���Ц��Ц��������ʲô��Ҫ˵��\n\n",name()));
	}

	else
	{
		tell_room(environment(),name()+"�Ҵ�ææ�����˳�ȥ��\n");
	
		move(environment(working));
	
		message_vision("\n$N�Ҵ�ææ�����˹������յ�$n����ߡ�\n\n",this_object(),working);
		tell_object(working,sprintf("%s�յ����ǰ�����صĳ���Ц��Ц��������ʲô��Ҫ˵��\n",name()));
	}

	set_leader(working);
	call_out("talking",3,0);
}

private void talking(int n)
{
	string fname,mname,sent;

	remove_call_out("talking");

	if(!objectp(working) || !objectp(master))
	{
		go_home();
		return;
	}

	fname = working->name();
	mname = master->name();
	sent = msg[n++];
	sent = replace_string(sent,"$FNAME",fname);
	sent = replace_string(sent,"$MNAME",mname);
	sent = replace_string(sent,"$FM",mname[0..1]);
	sent = replace_string(sent,"$FF",fname[0..1]);

	if(environment(working) != environment())
	{
		message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N����ææ�����˹�����\n",this_object());
	}

	command(sprintf("tell %s %s\n",working->query("id"),sent));

	if(n >= sizeof(msg))
	{
		chk_flag = 1;
		call_out("check_result",6,0,0);
		return;
	}

	call_out("talking",6,n);
}

private void check_result(int n,int times)
{
	string fname,mname,sent;

	if(!chk_flag)
		return;

	if(!objectp(working) || !objectp(master))
	{
		chk_flag = 0;
		go_home();
		return;
	}

	fname = working->name();
	mname = master->name();
	sent = shy_msg[n++];
	sent = replace_string(sent,"$FM",mname[0..1]);

	if(environment(working) != environment())
	{
		message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N����ææ�����˹�����\n",this_object());
	}

	command(sprintf("tell %s %s\n",working->query("id"),sent));

	if(n >= sizeof(shy_msg))
	{
		if(!times)
		{
			times++; n = 0;

		}
		else
		{
			chk_flag = 0;
			command("sigh");
			go_home();
			return;
		}
	}

	call_out("check_result",6,n,times);
}

void find_emote(object who,string verb)
{
	if(!who || !chk_flag)
		return;

	if( (who == working) && (verb == "nod") )
	{
		chk_flag = 0;
		call_out("do_success",2);
	}
}

private void do_success()
{
	object jf,jz;

	if(!objectp(working))
	{
		command("sigh");
		go_home();
		return;
	}

	if(!objectp(master))
	{
		command(sprintf("tell %s �����ƣ��˼ҵȲ����Ѿ����ˣ���������Ҫ�ź������ء�\n",working->query("id")));
		command("sigh");
		go_home();
		return;
	}

	if(environment() == find_object(query("startroom")))
	{
		environment()->no_out(working);
		environment()->no_out(master);
		command(sprintf("tell %s ������Ǻø�����������ͬ���ˣ�\n",master->query("id")));
		message_vision("$NЦ�Ǻǵ�˵������ϲ��λ�����Ѿ�����ȥ�����ù����������Ͼ������ֻ���\n",this_object());
		call_out("come_zhuchi",4);
		return;
	}

	command(sprintf("tell %s ������Ǻø�����������ͬ���ˣ�����Ͱ����ӻ����������ĵȻ����\n",master->query("id")));

	if(environment(working) != environment())
	{
		message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());
		this_object()->move(environment(working));
		message_vision("$N����ææ�����˹�����\n",this_object());
	}

	message_vision("$N������һ���֣������η�̧��һ��С�����˹�����\n",this_object());

	jf = new(__DIR__"jiaofu");
	jf->move(environment());
	jf = new(__DIR__"jiaofu");
	jf->move(environment());
	jz = new(__DIR__"obj/huajiao");
	jz->move(environment());

	message_vision(sprintf("$N��$n����%s��\n",jz->name()),this_object(),working);
	working->move(jz);
	jz->begin_walking();
	message_vision("$N���Žη�Ҵ�ææ�����ˡ�\n");

	set_leader(0);
	filter_array(all_inventory(environment()),(: $1->is_marry_ob() :) )->move(VOID_OB);
	call_out("arrive",18,jz);
}

private void arrive(object jz)
{
	object home = find_object(query("startroom")),*obs;

	if(!home)
		home = load_object(query("startroom"));
	if(!home)
	{
		if(working)
		{
			tell_object(working,"\nһ���粻֪�����㴵����ʲô�ط���\n");
			working->move("/d/changan/jiulou");
		}

		obs = filter_array(all_inventory(environment())-({this_object()}), (: $1->is_marry_ob() :) );
		for(int i=0;i<sizeof(obs);i++)
			destruct(obs[i]);
		destruct(this_object());
		return;
	}

	filter_array(all_inventory(environment()),(: $1->is_marry_ob() :) )->move(home);

	message_vision("$N���������η�̧��һ��С�������˽�����\n",this_object());

	tell_object(working,"ý��һ�ý������������ȥ��\n");
	working->move(home);
	tell_room(home,sprintf("ý��һ�ý����ѷ�%s��������\n",working->name()),({this_object(),working}));

	tell_room(home,"�η�С����̧�˳�ȥ��\n");
	obs = filter_array(all_inventory(environment())-({this_object()}), (: $1->is_marry_ob() :) );
	for(int i=0;i<sizeof(obs);i++)
		destruct(obs[i]);

	if(!master)
	{
		message_vision("$N�Ĵ�������$n˵��������ôû�ˣ����Գƴ����ģ�������������������
	��Ҳ���ܼ�����������ܣ��緢�����Ǻ����飬����ȥæ��İɣ��Ժ�
	Ҫ�Ǽ�������һ����������������\n",this_object(),working);
		fail();
		return;
	}

	else if(environment(master) != home)
	{
		command(sprintf("tell %s �������Ѿ����������Ͻ���ѽ��\n",master->query("id")));
		command(sprintf("tell %s ���ɳ�ȥ����������Ͼ����������һ����ɡ�\n",working->query("id")));
		wait = 1;
		home->no_out(working);
		call_out("waiting",5,0);
		return;
	}

	home->no_out(working);
	home->no_out(master);
	message_vision("$NЦ�Ǻǵ�˵������ϲ��λ�����Ѿ�����ȥ�����ù����������Ͼ������ֻ���\n",this_object());

	call_out("come_zhuchi",4);
}

void init()
{
	if( wait && objectp(master) && (this_player() == master))
	{
		wait = 0;
		environment()->no_out(master);
		call_out("come_on",1);
	}
}

private void come_on()
{
	if( master && (environment(master) == environment()) )
	{
		message_vision("$NЦ������ӭ��$n˵��������������������Ӷ���ȼ�������������",
			this_object(),master);
		remove_call_out("waiting");
		message_vision("$NЦ�Ǻǵ�˵������ϲ��λ�����Ѿ�����ȥ�����ù����������Ͼ������ֻ���\n",this_object());
		call_out("come_zhuchi",4);
	}
}

private void waiting(int times)
{
	if(times > 10)
	{
		if(objectp(master))
			command(sprintf("tell %s ���ˣ���Ҳ�����ˣ��������Ѿ��Ȳ������ˣ�\n",master->query("id")));
		if(objectp(working))
		{
			environment()->can_out(working);
			message_vision("$N�Ĵ�������$n˵������������̫��������Գƴ����ģ�������������������
	��Ҳ���ܼ�����������ܣ��緢�����Ǻ����飬����ȥæ��İɣ��Ժ�
	Ҫ�Ǽ�������һ����������������\n",this_object(),working);
		}
		wait = 0;
		fail();
		return;
	}

	if(!master)
	{
		if(objectp(working))
		{
			environment()->can_out(working);
			message_vision("$N�Ĵ�������$n˵������������̫��������Գƴ����ģ�������������������
	��Ҳ���ܼ�����������ܣ��緢�����Ǻ����飬����ȥæ��İɣ��Ժ�
	Ҫ�Ǽ�������һ����������������\n",this_object(),working);
		}
		wait = 0;
		fail();
		return;
	}

	if(!working)
	{
		if(objectp(master))
			command(sprintf("tell %s ���ˣ���Ҳ�����ˣ��������Ѿ��Ȳ������ˣ�\n",master->query("id")));
		wait = 0;
		fail();
		return;
	}

	command(sprintf("tell %s �㵽�ǿ��ѽ�������Ӷ�Ҫ�Ȳ����ˣ�\n",master->query("id")));
	message_vision("$NЦ�����Ķ�$n˵�����ٵȻ�����Ϳ�������\n",this_object(),working);
	call_out("waiting",6,++times);
}

private void come_zhuchi()
{
	object tang;

	if(!objectp(master) || !(working))
	{
		message_vision("$N����һ��˵������û�������������ˣ������������������æ��һ����\n",this_object());
		if(master)
			environment()->can_out(master);
		if(working)
			environment()->can_out(working);
		fail();
		return;
	}

	tang = new(__DIR__"litang");
	tang->move(environment());
	message_vision("\n$N���ŷ������˽�����\n",tang);
	message_vision("\n$NһŤ����ӭ��ȥ˵������ѽ���ʹ���������������˾͵����������ֻ�������\n",this_object());
	tang->begin_hunli(master,working);
}

// ��˫ϲ��
void finish_yishi()
{
	call_out("end",3);
}

private void end()
{
/*
	environment()->set("exits/eastup",__DIR__"sxg");
	message_vision("\n$N������ĺ�ľ�Ŵ򿪡�\n");
*/
	command("open door");
	message_vision("\n$N˵����������¥���ǡ�˫ϲ���������������Ҫ���л��磬��ȥ������(pai)���������
	ף��λ��������ͬ�ģ���ͷ���ϡ�����\n",
		this_object());
	fail();
}
