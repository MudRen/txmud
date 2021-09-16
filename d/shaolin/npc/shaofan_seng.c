// shaofan_seng.c

#include <ansi.h>
#define MAX_EXP		70000

inherit NPC;

int ask_food(object me);
int ask_job(object me);
void give_prise(object me);

void create()
{
	set_name("�շ�ɮ", ({ "shaofan seng", "seng" }) );

	set("class","shaolin");
	create_family("������", 37, "����");

	set("gender", "����" );
	set("age", 55);
	set("long", "����һλ��ü��Ŀ����ɮ������
�������˼�ʮ��ķ�����Ҫ�Ƕ�
�˿�������Ҫ��Ե�(food)��\n");
	set("attitude", "peaceful");
	set("inquiry",([
	"�Ե�" : (: ask_food :),
	"food" : (: ask_food :),
	"job"  : (: ask_job :),
]));

	set("combat_exp", 250);
	set("str", 67);

	setup();

	carry_object(__DIR__"obj/seng_pao")->wear();
}

int ask_food(object me)
{
	object *inv,food;
	int n,i;

	if(!me || me->query("class") != "shaolin")
		return 0;
	if(base_name(environment()) != query("startroom"))
		return 0;

	if((int)me->query("food") >= (int)me->max_food_capacity() )
	{
		message_vision(CYN"$N���˿�$n˵������������������֮�أ�\
����ô������ǳԣ���������������ҡ���\n"NOR,this_object(),me);
		return 1;
	}

	if(me->query_temp("shaolin_ask_food"))
	{
		message_vision(CYN"$N���˿�$n˵���������Ǹո������ô��Ҫ��\
����û�У�����\n"NOR,this_object(),me);
		return 1;
	}

	inv = all_inventory(me);

	n = sizeof(inv);
	for(i=0;i<n;i++)
	{
		if(inv[i]->is_food() && inv[i]->query("food_remaining"))
			break;
	}

	if(i<n)
	{
		message_vision(CYN"$N���˿�$n˵���������ǲ��ǻ��гԣ�\
�������������ҡ������˲����˷ѡ���\n"NOR,this_object(),me);
		return 1;
	}

	message_vision("$N���ͷ����������������$n����\n",this_object(),me);
	food = new(__DIR__"obj/mo");
	food->move(me);
	food = new(__DIR__"obj/mo");
	food->move(me);
	me->set_temp("shaolin_ask_food",1);
	call_out("finish",120,me);
	return 1;
}

void finish(object me)
{
	if(!me)
		return;
	me->delete_temp("shaolin_ask_food");
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
		write("�շ�ɮ˵���������������ҪӦ�����޳֣���Щ�����ø����ŵĵ����������ˡ���\n");
		return 1;
	}

	if(chai = me->query_temp("shaolinjob/dashui"))
	{
		ob = present("shui tong",me);
		if(!ob)
		{
			message_vision("$N������$n�ʵ��������ʴ�ʦ��ʲô���ܰ������������𣿡�\n",me,this_object());
			message_vision("$n��$N�ʵ���������ȥ��ˮ��ô��û��������ȥ�ɻ�ɡ���\n",me,this_object());
			return 1;
		}

		message_vision("$N����$n˵��������ʦ��Ȫˮ�����ˣ��㿴���������\n",me,this_object());
		if( ob->query("no_water") )
		{
			message_vision("$n��$N˵���������ˮͰ��ô���ǿյģ���ô���ҿ���Ц����\n",me,this_object());
			return 1;
		}

		if(chai < 18)
		{
			message_vision("$n��$N˵�����������˲�������Ͱˮ�����㵣��ɽ���ģ������շ���һ���Ҿ������ˡ���\n",me,this_object());
			destruct(ob);
			me->delete_temp("shaolinjob/dashui");
			return 1;
		}
		destruct(ob);
		give_prise(me);
		return 1;
	}

	message_vision("$N������$n�ʵ��������ʴ�ʦ��ʲô���ܰ������������𣿡�\n",me,this_object());
	time = time();
	t = me->query("shaolin_job/dashui/time");
	if( (time - t) >= 43200 )
	{
		me->set("shaolin_job/dashui/time",time);
		me->set("shaolin_job/dashui/n",1);
	}
	else
	{
		n = me->query("shaolin_job/dashui/n");
		if(n >= 50)
		{
			message_vision("$n��$N˵����������ûʲô�������ˣ���ȥæ��İɡ���\n",me,this_object());
			return 1;
		}
		else
			me->add("shaolin_job/dashui/n",1);
	}

	ob = new(__DIR__"obj/shuitong");
	message_vision("$n��$N�ʵ���������ˮ�����ˮ�����ˣ���ȥ��ɽ����ɽȪ���Ҵ�һͰ���ɡ���\n",me,this_object());
	ob->move(this_object());
	command("give shui tong to "+me->query("id"));
	me->set_temp("shaolinjob/dashui",1);
	return 1;

}

void give_prise(object me)
{
	int exp_gain,qn_gain;

	if(!me || me->query("class") != "shaolin")
		return;

	me->delete_temp("shaolinjob/dashui");

	exp_gain = 40 + random(20);
	qn_gain = 5 + random(5);

	me->add("combat_exp",exp_gain);
	me->add("potential",qn_gain);

	message_vision("$N����$n��ͷ˵�������ܺã�лл���ˡ���\n",this_object(),me);
	write(sprintf("�������ˮ�õ���%s�㾭���%s��Ǳ�ܡ�\n���%s����������\n",
		chinese_number(exp_gain),chinese_number(qn_gain),to_chinese("dodge")));
	me->improve_skill("dodge",5+random(5));
	me->add("family/gongji",10);
	return;
}