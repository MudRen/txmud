// tangzhong.c

inherit NPC;

string ask_me(object who);

nomask int is_doctor() {return 1;}
protected void do_cure(object, string);

void create()
	{
	set("class", "tangmen");

	set_name("����", ({"doctor zhong"}));
	set("title", "�ɺ�ҩ������");

	set("long", @TEXT
��������һ�����������ˣ�����΢����
��ȴ�ǳ���ӱ�����ϱ�����߶��Ŀ
����ʮ�꣬�Ը��ֶ����о��мӣ���
���ó��ⶾ��
TEXT
);

	set(NO_KILL, 1);

	set("gender","����");
	set("age",65);
	set("con",20);
	set("str",20);
	set("combat_exp",200);
	set("inquiry",([
	"����" : (: ask_me :),
	"��ҩ" : (: ask_me :),
	]));

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
	{
	::init();
	add_action("do_ask", "ask");
}

int do_ask( string arg )  /* return 0 let ask command process this action. */
{
	object me = this_player();
	string name, what;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !arg || !stringp(arg) )
		return 0;

	if( sscanf( arg, "%s about %s", name, what ) != 2 )
		return 0; 

	if( !id(name) )
		return 0;

	if(me->query("class") != "tangmen")
	{
		write("�������ŵ����⿪��ڡ�\n");
		return 1;
	}

	if( what != "����" && what != "�ⶾ" )
		return 0;

	if( what == "����"
	&& me->query("eff_kee") >= me->query("max_kee")
	&& me->query("eff_gin") >= me->query("max_gin")
	&& me->query("eff_sen") >= me->query("max_sen") )
	{
		write(sprintf("%s��������һ��˵������λ%s��ɫ����û������ѽ��\n",
			name(),RANK_D->query_respect(me)));
		return 1;
	}

	if( (what == "�ⶾ")
	&& !me->query_condition("snake_poison")
	&& !me->query_condition("tangdu")
	&& !me->query_condition("mabi") )
	{
		write(sprintf("%sҡҡͷ˵����������ʲô�����ҿ���������\n",name()));
		return 1;
	}

	if( me->query_condition("heal_up") )
	{
		write(name()+"˵���������ϴο����õ�ҩ��û��ʧЧ����������ҩ�ˣ�������������ɡ���\n");
		return 1;
	}

	do_cure(me, what);
	return 1;
}

protected void do_cure( object me, string what )
	{
	switch( what )
	{
		case "����" :
			write(sprintf("%s�˳�һ����ҩ���������ȥ��Ȼ��˵�������ú���Ϣ��������ͻ�õġ���\n",name()));
			me->apply_condition("heal_up", 20 );
			break;

		case "�ⶾ" :
			/* ����һ��Ķ���ɺ���������ϣ�����Ķ�Ӧ���ɱ��˵����ƽ�ҩ�������н����*/

			write(name()+"�˳�һ��ҩ��������ֿ��˿���˵���������ˣ������ڵĶ��Ѿ��ξ��ˡ���\n");
			me->clear_condition("snake_poison");
			me->clear_condition("mabi");
			me->clear_condition("tangdu");
			break;
        }
}

string ask_me(object who)
{
	object ob;

	if( (who->query("class") != "tangmen")
	|| (who->query("quest/tangmen_quest/name") != "��ҩ") )
		return 0;

	if(who->query("quest/tangmen_quest/zhong_give"))
		return "�������Ƕ��������ˣ��Ͻ�ȥ�ɰɡ�";

	if(!ob = present("yao chu",who))
	{
		ob = new(__DIR__"obj/yaochu");
		if(!ob->move(who))
		{
			ob->move(environment());
			message_vision("$N��һ��ҩ�����ڵ��ϡ�\n",this_object());
		}
		else
			message_vision("$N��$nһ��ҩ����\n",this_object(),who);

	who->set("quest/tangmen_quest/zhong_give",1);

	return "��ȥҩ�ԲɿŲ�ҩ��Ȼ���õ���ҩ��������һ�ŵ�Ȼ��ȥ���";
	}
}
