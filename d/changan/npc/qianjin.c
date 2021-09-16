// qianjin.c

inherit NPC;

int have = 0;

void create()
{
	set_name("������", ({"lin qiuwen", "qiuwen"}));
	set("title","ة��ǧ��");

	set("long", "��λ�����ฮ��ǧ��");
	set("gender","Ů��");
	set("attitude","peaceful");

        set("age",15);
	set("per",35);
	set("max_kee",1500);

	set_skill("unarmed",20);

        set("combat_exp",6000+random(6000));

        setup();
        carry_object(__DIR__"obj/buqun")->wear();
}

int accept_kill(object me)
{
	object ob,girl;

	message_vision("$N����������ѽ���������ģ�����ѽ������\n\n",this_object());
	if(objectp(girl = present("servant girl",environment())) && living(girl))
		tell_room(environment(),"СѾ�߼������������������ģ����˴�ɱС����������\n");

	me->set_temp("chengxf_killer",1);

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

	if(have)
		return;

	message_vision("$N��������������ѽ������͵������������\n\n",this_object());

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