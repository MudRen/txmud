// furen.c

inherit NPC;

int have = 0;
 
void create()
{
	set_name("ة�����", ({"fu ren"}));
	set("long", @LONG
��λ���ǵ�����������η�ķ��ˡ��������ڽ���
���������彿С�㣬�Լ޸���ة�࣬�����ӣ�
����׿����ֻ������̬�򷽡�
LONG
);
	set("gender","Ů��");
        set("age",35);
        set("per",35);
	set("attitude","peaceful");

	set_skill("unarmed",50);

        set("combat_exp",2000+random(2000));

        setup();
	carry_object(__DIR__"obj/hongduan_skirt")->wear();
	carry_object(__DIR__"obj/zhuhua")->wear();
}

int accept_fight(object me)
{
	if(base_name(environment()) == query("startroom"))
		message_vision("$N����$n˵���������������ģ���ô���ܵ�ة�ฮ��Ұ������\n",
		this_object(),me);
	return 0;
}

int accept_kill(object me)
{
	object ob;

	message_vision("$N��������Ҫ�췴�������ˣ����������ȥ������\n\n",this_object());

	if(have)
		return 1;

	for(int i=0;i<2;i++)
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

	message_vision("$N�����������ҵ�����͵���������ˣ����������ȥ������\n\n",this_object());

	if(have)
		return;

	for(int i=0;i<2;i++)
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