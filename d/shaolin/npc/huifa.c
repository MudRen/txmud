// huifa.c
// 四罗汉之一

inherit NPC;

string ask_me(object me);
string *to_t_zhen = ({"east","southeast","south","south","west"});
int doing_zhen = 0;
void do_return();
object in_waiting,*p_obs,wait_win;

void create()
{
	set_name("晦法", ({ "hui fa" }) );

	set("class","shaolin");
	create_family("少林寺", 36, "弟子");

	set_auto_recover(1);
	set(NO_KILL, 1);

	set("gender", "男性" );
	set("age", 53);
	set("long", "这是一位晦字辈的高僧，江湖上赫赫有名
的少林寺四大罗汉之一。\n");

	set("inquiry",([
	"铜人阵" : (: ask_me :),
]));

	set("combat_exp", 3000000);
	set("str", 100);
	set("max_kee",4000);
	set("kee",4000);
	set("max_gin",4000);
	set("gin",4000);
	set("max_sen",4000);
	set("sen",4000);
	set("force", 6000);
	set("max_force", 6000);
	set("atman", 4000);
	set("max_atman", 4000);
	set("mana", 4000);
	set("max_mana", 4000);
	set("force_factor", 350);

	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
}));

	set_skill("unarmed",260);
	set_skill("dodge",260);
	set_skill("parry",250);
	set_skill("force",200);
	set_skill("stick",200);
	set_skill("iron-cloth",260);
	set_skill("perception",260);
	set_skill("yiqi-force",200);
	set_skill("ganchan",250);
	set_skill("luohan-quan",250);
	set_skill("weituo-gun",250);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("unarmed","luohan-quan");
	map_skill("stick","weituo-gun");

	setup();

	carry_object(WEAPON_DIR"stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}

void init()
{
	object ob = previous_object();

	if(!doing_zhen || !ob)
		return;

	if(objectp(in_waiting) && in_waiting == ob)
	{
		if(find_call_out("do_return"))
			remove_call_out("do_return");
		in_waiting = 0;
		call_out("check_player",2,ob);
		return;
	}

	if(objectp(wait_win) && wait_win == ob)
	{
		if(ob->query_temp("pass_tongren") != 3)
			call_out("is_fail",2,ob);
		else
			call_out("is_win",2,ob);
	}
}

void is_fail(object me)
{
	string say;

	if(!me || environment(me) != environment())
		return;

	say = sprintf("\n%s朝你叹了一口气说道：",name());
	if(p_obs && sizeof(p_obs))
	{
		p_obs->move(me);
		say += "东西都给你，";
	}

	say += "还要好好努力呀。\n\n";

	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("%s(%s) 试闯『铜人阵』在第%s关失败了。\n",
		me->name(),capitalize(me->query("id")),chinese_number(me->query_temp("pass_tongren")+1) ));

	me->delete_temp("pass_tongren");

	tell_object(me,say);
	wait_win = 0;
	call_out("do_return",2);
}

void is_win(object me)
{
	string say;

	if(!me || environment(me) != environment())
		return;

	say = sprintf("\n%s高兴的说道：",name());
	if(p_obs && sizeof(p_obs))
	{
		p_obs->move(me);
		say += "东西都给你，";
	}

	say += "真是后生可畏呀，快去找方丈报喜吧！。\n\n";
	tell_object(me,say);
	wait_win = 0;
	call_out("do_return",2);
}

string ask_me(object me)
{
	if( doing_zhen
	|| me->query("class") != "shaolin"
	|| me->query("family/generation") > 38
	|| !me->query_temp("fangzhang_pass")
	|| base_name(environment()) != query("startroom"))
		return 0;

	set("no_return_home",1);
	doing_zhen = 1;

	call_out("do_go",3,0,me);
	me->set_leader(this_object());
	return "既然得到方丈的许可，你就跟我来吧。";
}

void do_go(int step,object me)
{
	remove_call_out("do_go");

	command(sprintf("go %s",to_t_zhen[step]));
	if(++step < sizeof(to_t_zhen))
	{
		call_out("do_go",2,step,me);
		return;
	}
	else
		call_out("check_player",3,me);
}

void check_player(object me)
{
	if(!me)
	{
		do_return();
		return;
	}

	if(environment(me) != environment())
	{
		in_waiting = me;
		call_out("do_return",10);
		return;
	}

	p_obs = filter_array( all_inventory(me)-({0}),(: !$1->is_weapon() && !$1->is_armor() :) );

	if(p_obs && sizeof(p_obs))
		p_obs->move(this_object());

	tell_object(me,sprintf("\n%s说道：“铜人阵凶险万分，你要小心行事！你身上没用的东西我先替你保管了”\n",
		name()));

	message_vision("\n$N在石壁上一推，东面闪出了一个小门。$N一把把$n推了进去。\n\n",this_object(),me);
	me->delete_temp("fangzhang_pass");
	me->set("family/try_tongren",time());
	environment()->do_open(me);
	command("go east");
	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("经方丈许可：%s %s(%s) 试闯『铜人阵』！\n",
		me->query("title"),me->name(),capitalize(me->query("id"))));
	wait_win = me;
	call_out("do_return",600);
}

void do_return()
{
	set("no_return_home",0);
	doing_zhen = 0;
	in_waiting = 0;
	wait_win = 0;
	p_obs = 0;

	if(!query("startroom"))
		return;

	message_vision("$N匆匆忙忙的走了。\n",this_object());
	this_object()->move(query("startroom"));
	message_vision("$N走了过来。\n",this_object());
}
