// shaofan_seng.c

#include <ansi.h>
#define MAX_EXP		70000

inherit NPC;

int ask_food(object me);
int ask_job(object me);
void give_prise(object me);

void create()
{
	set_name("烧饭僧", ({ "shaofan seng", "seng" }) );

	set("class","shaolin");
	create_family("少林寺", 37, "弟子");

	set("gender", "男性" );
	set("age", 55);
	set("long", "这是一位慈眉善目的老僧，在少
林寺烧了几十年的饭。你要是饿
了可以找他要点吃的(food)。\n");
	set("attitude", "peaceful");
	set("inquiry",([
	"吃的" : (: ask_food :),
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
		message_vision(CYN"$N看了看$n说道：“少林寺是清修之地，\
你怎么整天就是吃？等真饿了再来找我。”\n"NOR,this_object(),me);
		return 1;
	}

	if(me->query_temp("shaolin_ask_food"))
	{
		message_vision(CYN"$N看了看$n说道：“不是刚给你的怎么又要？\
现在没有！！”\n"NOR,this_object(),me);
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
		message_vision(CYN"$N看了看$n说道：“你那不是还有吃？\
吃完了再来找我。出家人不可浪费。”\n"NOR,this_object(),me);
		return 1;
	}

	message_vision("$N点点头，将两个馍塞给了$n。”\n",this_object(),me);
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
		write("烧饭僧说道：“既入佛门主要应勤于修持，这些杂事让刚入门的弟子作就行了。”\n");
		return 1;
	}

	if(chai = me->query_temp("shaolinjob/dashui"))
	{
		ob = present("shui tong",me);
		if(!ob)
		{
			message_vision("$N恭身向$n问道：“请问大师有什么我能帮着做的事情吗？”\n",me,this_object());
			message_vision("$n对$N问道：“让你去担水怎么还没打来，快去干活吧。”\n",me,this_object());
			return 1;
		}

		message_vision("$N对着$n说道：“大师，泉水打来了，你看放在哪里？”\n",me,this_object());
		if( ob->query("no_water") )
		{
			message_vision("$n对$N说道：“你的水桶怎么还是空的？怎么跟我开玩笑！”\n",me,this_object());
			return 1;
		}

		if(chai < 18)
		{
			message_vision("$n对$N说道：“出家人不打谎语，这桶水不是你担上山来的，不过烧饭都一样我就收下了。”\n",me,this_object());
			destruct(ob);
			me->delete_temp("shaolinjob/dashui");
			return 1;
		}
		destruct(ob);
		give_prise(me);
		return 1;
	}

	message_vision("$N恭身向$n问道：“请问大师有什么我能帮着做的事情吗？”\n",me,this_object());
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
			message_vision("$n对$N说道：“我这没什么事情做了，你去忙别的吧。”\n",me,this_object());
			return 1;
		}
		else
			me->add("shaolin_job/dashui/n",1);
	}

	ob = new(__DIR__"obj/shuitong");
	message_vision("$n对$N问道：“我这水缸里的水不够了，你去半山腰的山泉帮我打一桶来吧。”\n",me,this_object());
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

	message_vision("$N朝着$n点头说道：“很好，谢谢你了。”\n",this_object(),me);
	write(sprintf("你帮着挑水得到了%s点经验和%s点潜能。\n你的%s有所长进。\n",
		chinese_number(exp_gain),chinese_number(qn_gain),to_chinese("dodge")));
	me->improve_skill("dodge",5+random(5));
	me->add("family/gongji",10);
	return;
}