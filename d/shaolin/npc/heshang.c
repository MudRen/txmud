// heshang.c

#define MAX_EXP	50000

inherit NPC;

int ask_job(object me);
void give_prise(object me);

void create()
{
	set_name("����", ({ "he shang" }) );
	set("long", "����һλ���ݵ�������С�\n");
	set("max_gin", 400);
	set("max_kee", 500);
	set("max_sen", 400);

	set("str", 30);
	set("cor", 20);
	set("con", 30);
	set("inquiry",([
	"job" : (: ask_job :),
]));

	set_skill("unarmed",1);
	set_skill("dodge",1);
	set("combat_exp",200);

	setup();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

int ask_job(object me)
{
	object ob;
	int time,n,t,chai;

	if(base_name(environment()) != query("startroom"))
		return 0;

	if(!me || me->query("class") != "shaolin")
		return 0;

	if(me->query("combat_exp") > MAX_EXP)
	{
		write("����˵���������������ҪӦ�����޳֣���Щ�����ø����ŵĵ����������ˡ���\n");
		return 1;
	}

	if(chai = me->query_temp("shaolinjob/kanchai"))
	{
		ob = present("mu chai",me);
		if(!ob)
		{
			message_vision("$N������$n�ʵ��������ʴ�ʦ��ʲô���ܰ������������𣿡�\n",me,this_object());
			message_vision("$n��$N�ʵ��������㿳�Ĳ�û��������ȥ�ɻ�ɡ���\n",me,this_object());
			return 1;
		}

		message_vision("$N����$n˵��������ʦ��ľ�񿳻����ˣ��㿴����������\n",me,this_object());
		if(ob->query_amount() < 30)
		{
			message_vision("$n��$N˵���������Ǻ���˵������ҲҪ��ʮ�����㿳��ô�������ʲô�á���\n",me,this_object());
			return 1;
		}

		if(chai < 31)
		{
			message_vision(sprintf("$n��$N˵�����������˲�������Щľ��%s���㿳�ģ������շ���һ���Ҿ������ˡ���\n",
				chai>1?"����":"����"),me,this_object());
			destruct(ob);
			me->delete_temp("shaolinjob/kanchai");
			ob = present("kanchai dao",me);
			if(objectp(ob))
				destruct(ob);
			return 1;
		}
		destruct(ob);
		give_prise(me);
		return 1;
	}

	message_vision("$N������$n�ʵ��������ʴ�ʦ��ʲô���ܰ������������𣿡�\n",me,this_object());
	time = time();
	t = me->query("shaolin_job/kanchai/time");
	if( (time - t) >= 43200 )
	{
		me->set("shaolin_job/kanchai/time",time);
		me->set("shaolin_job/kanchai/n",1);
	}
	else
	{
		n = me->query("shaolin_job/kanchai/n");
		if(n >= 50)
		{
			message_vision("$n��$N˵����������ûʲô�������ˣ���ȥæ��İɡ���\n",me,this_object());
			return 1;
		}
		else
			me->add("shaolin_job/kanchai/n",1);
	}

	ob = new(__DIR__"obj/kanchaidao");
	message_vision("$n��$N�ʵ����������շ��Ĳ�𲻹��ˣ���ȥ��ɽ���ҿ���ɣ�����ҲҪ��ʮ������\n",me,this_object());
	ob->move(this_object());
	command("give kanchai dao to "+me->query("id"));
	me->set_temp("shaolinjob/kanchai",1);
	return 1;
}

void give_prise(object me)
{
	object ob;
	int exp_gain,qn_gain;

	if(!me || me->query("class") != "shaolin")
		return;

	ob = present("kanchai dao",me);
	if(objectp(ob))
		destruct(ob);

	me->delete_temp("shaolinjob/kanchai");

	exp_gain = 40 + random(20);
	qn_gain = 5 + random(5);

	me->add("combat_exp",exp_gain);
	me->add("potential",qn_gain);

	message_vision("$N����$n��ͷ˵�������ܺã�лл���ˡ���\n",this_object(),me);
	write(sprintf("����ſ���õ���%s�㾭���%s��Ǳ�ܡ�\n",
		chinese_number(exp_gain),chinese_number(qn_gain)));
	me->add("family/gongji",12);
	return;
}