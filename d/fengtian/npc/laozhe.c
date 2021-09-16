// laozhe.c

inherit NPC;

object who;
private string where = "/d/fengtian/quest3";
private int checking;

int is_rain_quest() { return 1;}
string ask_me(object usr);

void create()
{
	set_name("����", ({"old man"}));
        set("long", "����һλ��С�ݸɵ����ߣ����������
��ʱ�����������ż����һ̧ͷ���۾���
ȴ͸¶��ֻ���ڹ����ֲŻ��еľ��⡣\n");
        set("gender","����");

        set("age",50);
        set("con",30);
        set("str",30);
	set("kar",30);
	set("cor",35);

	set("inquiry",([
	"��ʮ��ǰ" : (: ask_me :),
]));

	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",50);

	set("attitude","peaceful");
	set("no_exp_gain",1);

	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(: perform_action, "unarmed.zui" :),
}));

        set("combat_exp",1500);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object usr)
{
	if(usr->query_temp("feiyu_upgrade_quest/ask_oldman"))
		return "���Ǻ���˵�ˣ�û��û�˵���ʲô��\n";

	if(usr->query_temp("feiyu_upgrade_quest/ask_liehu"))
	{
		usr->set_temp("feiyu_upgrade_quest/ask_oldman",1);
		return "��ɽ��������֪���ˡ�\n";
	}
	return 0;
}

private void down()
{
	delete_all_skills();
	set("combat_exp",1500);
}

private void up()
{
	set_skill("parry",150);
	set_skill("dodge",150);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("piaoyu-steps",160);
	set_skill("zuiyue-strike",150);
	set_skill("suiyu-force",150);
	map_skill("force","suiyu-force");
	map_skill("unarmed","zuiyue-strike");
	map_skill("dodge","piaoyu-steps");
	set("combat_exp",2000000);
}

void init()
{
	object env;
	string start;

	if(!objectp(env = environment()))
	{
		call_out("leave",1);
		return;
	}

	if(!stringp(start = query("startroom")))
	{
		call_out("leave",1);
		return;
	}

	if( base_name(env) == start )
		return;

	if( (base_name(env) == where) && !objectp(who))
	{
		who = query_leader();
		set_leader(0);

		if(objectp(who))
		{
			env->delete("exits/out");
			call_out("begin",1,who);
		}
	}
}

private void begin(object user)
{
	object env;

	if(!user)
		call_out("leave",1);

	message_vision("$N����$nһ����Ц��ס�˳��ڡ�\n",this_object(),who);
	up();
	message_vision("$N������С���ǿ�����������ĳ�������������������������\n",this_object());

	env = environment();

	for(int i=0;i<3;i++)
	{
		object ob = new(__DIR__"bangshou");
		ob->move(env);
		message_vision("$N���˳�����\n",ob);
		ob->kill_ob(user);
		user->kill_ob(ob);
	}

	this_object()->kill_ob(user);
	user->kill_ob(this_object());
	checking = 1;
}

private void leave()
{
	destruct(this_object());
}

void char_was_died(object player,object corpse)
{
	if(player == who)
		call_out("leave",1);
}

void die()
{
	if(environment())
		environment()->do_check();
	::die();
}

int heal_up()
{
	if(!checking)
		return ::heal_up();

	if(!who)
	{
		call_out("leave",1);
		return 1;
	}

	if(living(this_object()) && !is_fighting())
	{
		call_out("leave",2);
		return 1;
	}

	return ::heal_up();
}
