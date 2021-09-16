// heshang.c

#define MAX_EXP	50000

inherit NPC;

int ask_job(object me);
void give_prise(object me);

void create()
{
	set_name("和尚", ({ "he shang" }) );
	set("long", "这是一位黑瘦的中年和尚。\n");
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
		write("和尚说道：“既入佛门主要应勤于修持，这些杂事让刚入门的弟子作就行了。”\n");
		return 1;
	}

	if(chai = me->query_temp("shaolinjob/kanchai"))
	{
		ob = present("mu chai",me);
		if(!ob)
		{
			message_vision("$N恭身向$n问道：“请问大师有什么我能帮着做的事情吗？”\n",me,this_object());
			message_vision("$n对$N问道：“让你砍的柴还没砍来，快去干活吧。”\n",me,this_object());
			return 1;
		}

		message_vision("$N对着$n说道：“大师，木柴砍回来了，你看够不够？”\n",me,this_object());
		if(ob->query_amount() < 30)
		{
			message_vision("$n对$N说道：“不是和你说了最少也要三十根，你砍这么点回来有什么用。”\n",me,this_object());
			return 1;
		}

		if(chai < 31)
		{
			message_vision(sprintf("$n对$N说道：“出家人不打谎语，这些木柴%s是你砍的，不过烧饭都一样我就收下了。”\n",
				chai>1?"不都":"都不"),me,this_object());
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

	message_vision("$N恭身向$n问道：“请问大师有什么我能帮着做的事情吗？”\n",me,this_object());
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
			message_vision("$n对$N说道：“我这没什么事情做了，你去忙别的吧。”\n",me,this_object());
			return 1;
		}
		else
			me->add("shaolin_job/kanchai/n",1);
	}

	ob = new(__DIR__"obj/kanchaidao");
	message_vision("$n对$N问道：“我这烧饭的柴火不够了，你去后山帮我砍点吧，最少也要三十根。”\n",me,this_object());
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

	message_vision("$N朝着$n点头说道：“很好，谢谢你了。”\n",this_object(),me);
	write(sprintf("你帮着砍柴得到了%s点经验和%s点潜能。\n",
		chinese_number(exp_gain),chinese_number(qn_gain)));
	me->add("family/gongji",12);
	return;
}