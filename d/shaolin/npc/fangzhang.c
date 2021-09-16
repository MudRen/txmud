// fangzhang.c

inherit NPC;
inherit F_MASTER;

string ask_me(object me);
string ask_yijin(object me);

void create()
{
	set_name("����", ({ "abbot huizhi", "huizhi", "abbot" }) );

	// master �ı�������.
	set("class","shaolin");
	create_family("������", 36, "����");
	set("inquiry",([
	"leave" : (: call_other, __FILE__, "want_to_leave" :),
	"�뿪" : (: call_other, __FILE__, "want_to_leave" :),
	"��ʦ" : (: call_other, __FILE__, "want_to_leave" :),
	"ͭ����" : (: ask_me :),
	"�׽" : (: ask_yijin :),
]));

	set("gender", "����" );
	set("age", 83);
	set("attitude", "peaceful");

	set("long", "����һλ��ü��Ŀ���Ϻ��У���������
�������η��ɻ��Ǵ�ʦ��\n");

	set("combat_exp", 6000000);
	set("str", 57);
	set("kar", 45);
	set("cor", 80);
	set("max_kee",3500);
	set("kee",3500);
	set("max_gin",3500);
	set("gin",3500);
	set("max_sen",3500);
	set("sen",3500);
	set("force", 5000);
	set("max_force", 5000);
	set("atman", 5000);
	set("max_atman", 5000);
	set("mana", 5000);
	set("max_mana", 5000);
	set("force_factor", 600);

	set_skill("dacheng-fofa",300);
	set_skill("chanting",500);
	set_skill("literate",300);
	set_skill("unarmed",280);
	set_skill("dodge",280);
	set_skill("parry",280);
	set_skill("force",280);
	set_skill("magic",300);
	set_skill("spells",250);
	set_skill("stick",280);
	set_skill("sword",260);
	set_skill("iron-cloth",300);
	set_skill("perception",300);
	set_skill("yiqi-force",280);
	set_skill("ganchan",280);
	set_skill("changquan",200);
	set_skill("cibei-blade",280);
	set_skill("damo-sword",260);
	set_skill("jingang",300);
	set_skill("blade",280);
	set_skill("luohan-quan",280);
	set_skill("weituo-gun",280);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("magic","dacheng-fofa");
	map_skill("iron-cloth","jingang");
	map_skill("unarmed","luohan-quan");

	setup();

	carry_object(__DIR__"obj/jiasha")->wear();
}

string ask_yijin(object me)
{
	string *ski;
	mapping all;
	int n;

	if( (me->query("class") != "shaolin")
	|| !me->is_apprentice_of(this_object()) )
		return 0;

	if(me->query("family/can_study_yijin"))
		return "�����Ѿ�׼������ޡ��׽���ˣ���ȥ�һ޳մ�ʦ�ɡ�\n";

	all = query_skills();
	ski = keys(all) - ({"chanting","literate","magic","spells","perception"});

	n = sizeof(ski);

	for(int i=0;i<n;i++)
		if( me->query_skill(ski[i],1) < (all[ski[i]] - 10) )
			return sprintf("��ġ�%s����Ϊ���㣬���޷������׽����\n",to_chinese(ski[i]));

	me->set("family/can_study_yijin",1);

	return "���׽����Ȼ��С�������ݲ���������˹�����������ѧ��Ҫ��
          ���ܲ���͸������ʹ�书����һ��¥��������˾�������
          Ҫ���ߵ��������ģ�����Ҫ����Ե������Ϊ�����ֺ�֮
          �е�ٮٮ�ߣ������ܲ�͸�˾�����������ѧ��������
          ����ȥ�һ޳մ�ʦ�ɡ�";
}

void attempt_apprentice(object ob)
{
	if(ob->query("gender") == "Ů��")
	{
		command("say �����²���Ů���ӣ���λŮʩ������뿪�ɡ�");
		return;
	}

	if(!ob->query("family/passed_tongren"))
	{
		command("say ���������Ѹߣ���ͽ�ڷ��Ѿ�����������������ˡ�");
		return;
	}

	else
	{
		command("smile");
		command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	::recruit_apprentice(ob);
	ob->set("class", "shaolin");
	return 1;
}

string ask_me(object me)
{
	int t;

	if(me->query("class") != "shaolin")
		return 0;

	if(me->query_temp("fangzhang_pass"))
		return "��������ȥ�һ޷���ʦ����\n";

	if(me->query("family/passed_tongren"))
		return "���ѹ���ͭ���󡻣��ú�ȥ������ѧ���𷨰ɡ�\n";

	if(me->query_temp("pass_tongren") == 3)
	{
		me->delete_temp("pass_tongren");
		me->delete("family/try_tongren");
		me->set("family/passed_tongren",1);
		call_out("do_reward",1,me);
		return "�ã��ã���Ȼ������ͭ���󡻣�ǰ;������������Ӧ������\n";
	}

	if( (t = me->query("family/try_tongren")) && (time() - t) < 86400 )
		return "���Թ�����ͭ���󡻣���Ϣ��Ϣ��˵��";

	if(me->query("family/generation") > 38)
		return "���Ⱥú�ȥ������ѧ���𷨰ɣ�����̰���ͽ���\n";

	me->set_temp("fangzhang_pass",1);
	return "���Ȼ�д���Ը��ȥ���԰ɣ���ȥ�һ޷���ʦ��\n";
}

protected void do_reward(object me)
{
	me->add("combat_exp",5000);
	me->add("potential",3000);
	me->add_shimen_gongji(3000);

	tell_object(me,sprintf("\n��õ��ˣ�\n\t%d ��ʵս����\n\t%d ��Ǳ��\n\t%d ��ʦ�ǹ���\n\n",
		5000,3000,3000));

	CHANNEL_D->do_channel(this_object(), "menpai",sprintf("%s %s(%s) �Դ���ͭ����ͨ������\n",
		me->query("title"),me->name(),capitalize(me->query("id"))));
}

int prevent_learn(object who, string skill)
{
	if(!who->query("is_bonze"))
		return notify_fail("����֮�˿���ȥ�Ҿ�Զʦ��ѧЩǿ����֮����\n");
	else if(who->query("bellicosity") > 100)
		return notify_fail(who->name()+"�Ĳ�ɱ����Ŀ¶�׹⣬����������ѧ֮��Ҫ��");
	else if(time() - who->query("eat_hun_food") < 1440)
	{
		message_vision("$N����$nҡҡͷ˵����������������֮�������ܳ�ȥ͵���˰ɣ�\n$n�������ֶ��ּ�װ�޹���˵������û�У�û�У���û�У���\n\n", this_object(), who);
		return 0;
	}
	else
		return ::prevent_learn(who,skill);
}
