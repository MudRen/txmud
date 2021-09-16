// huifa.c
// ���޺�֮һ

inherit NPC;

string ask_me(object me);
string *to_t_zhen = ({"east","southeast","south","south","west"});
int doing_zhen = 0;
void do_return();
object in_waiting,*p_obs,wait_win;

void create()
{
	set_name("�޷�", ({ "hui fa" }) );

	set("class","shaolin");
	create_family("������", 36, "����");

	set_auto_recover(1);
	set(NO_KILL, 1);

	set("gender", "����" );
	set("age", 53);
	set("long", "����һλ���ֱ��ĸ�ɮ�������Ϻպ�����
���������Ĵ��޺�֮һ��\n");

	set("inquiry",([
	"ͭ����" : (: ask_me :),
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

	say = sprintf("\n%s����̾��һ����˵����",name());
	if(p_obs && sizeof(p_obs))
	{
		p_obs->move(me);
		say += "���������㣬";
	}

	say += "��Ҫ�ú�Ŭ��ѽ��\n\n";

	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("%s(%s) �Դ���ͭ�����ڵ�%s��ʧ���ˡ�\n",
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

	say = sprintf("\n%s���˵�˵����",name());
	if(p_obs && sizeof(p_obs))
	{
		p_obs->move(me);
		say += "���������㣬";
	}

	say += "���Ǻ�����ηѽ����ȥ�ҷ��ɱ�ϲ�ɣ���\n\n";
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
	return "��Ȼ�õ����ɵ���ɣ���͸������ɡ�";
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

	tell_object(me,sprintf("\n%s˵������ͭ����������֣���ҪС�����£�������û�õĶ����������㱣���ˡ�\n",
		name()));

	message_vision("\n$N��ʯ����һ�ƣ�����������һ��С�š�$Nһ�Ѱ�$n���˽�ȥ��\n\n",this_object(),me);
	me->delete_temp("fangzhang_pass");
	me->set("family/try_tongren",time());
	environment()->do_open(me);
	command("go east");
	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("��������ɣ�%s %s(%s) �Դ���ͭ���󡻣�\n",
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

	message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());
	this_object()->move(query("startroom"));
	message_vision("$N���˹�����\n",this_object());
}
