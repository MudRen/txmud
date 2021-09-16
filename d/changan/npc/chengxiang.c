// chengxiang.c

inherit NPC;

int have;

void create()
{
	set_name("����η", ({"lin wenwei", "wenwei", "lin"}));
	set("title","��������");

	set("long", @LONG
�����ǵ�����ة�࣬��˵������ϵ�̫�ӵ�ʱ��һ
���ڹ������ѣ���ʱ�����������ة��������ȣ�
̫�ӵǻ��Ժ����һ����Σ���ة���Լ�Ҳ�Ǿ���
ҵҵ�������Ļ��ϵĳ谮��
LONG
);

	set("gender","����");
	set("vendetta_mark", "guanfu");
	set("attitude","peaceful");

        set("age",55);
	set("str",45);
	set("kar",45);

	set("max_kee",2500);
	set("max_gin",2500);
	set("max_sen",2500);

	set_skill("unarmed",160);
	set_skill("dodge",160);
	set_skill("parry",160);

        set("combat_exp",1000000);

        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
}

void init()
{
	object ob;

	::init();
	if( living(ob = previous_object()) && ob->query_temp("chengxf_killer") )
	{
		message_vision("$N����$n���������ҵ�ة�ฮ���ף����������أ�����\n",
			this_object(),ob);
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
}

int accept_kill(object me)
{
	object ob;

	message_vision(sprintf("$N������������Ҫ�췴�������ˣ�����%s�������ˣ�����\n\n",
		gender_pronoun(me->query("gender"))),this_object());

	me->set_temp("chengxf_killer",1);

	if(have)
		return 1;

	for(int i=0;i<3;i++)
	{
		ob = new(__DIR__"cxf_huyuan");
		ob->move(environment());
		message_vision("$N���������˽�����������С�ӣ�����𣿣���\n\n",ob);
		ob->set_leader(me);
		ob->kill_ob(me);
		me->fight_ob(ob);
	}

	have = 1;

	return 1;
}


void detect_stealing(object me)
{
	object ob;

	if(!me)
		return;

	message_vision(sprintf("$N���������ø�Сë���ҵ�����͵���������ˣ�����%s�������ˣ�����\n\n",
		gender_pronoun(me->query("gender"))),this_object());

	if(have)
		return;

	for(int i=0;i<3;i++)
	{
		ob = new(__DIR__"cxf_huyuan");
		ob->move(environment());
		message_vision("$N���������˽�����������С�ӣ�����𣿣���\n\n",ob);
		ob->set_leader(me);
		ob->kill_ob(me);
		me->fight_ob(ob);
	}

	have = 1;

	return;
}