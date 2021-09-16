// tangzhong.c

inherit NPC;

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

int ask_quest(object me)

	object me, du;
	string msg, targ;
	int coun;

	string *targ = ({
		"����","����","ޢ��","����","ţ��","����","ʯέ","������","���Ƥ"
	});

	me = this_player();
	du = this_object();

	{
	if( (me->query("quest/tangmen_quest/name") != "����")
	command(sprintf("say %s","����ȥҩ�Բɿ�ҩ�ģ�Ȼ����ȥ��ҩ��������"));
	me->set_temp("asked_tangzhong",1);
	return 1;
	}

	{
		if ( (int)me->query_temp("yao") )
		{
	                command("say ���㻹û����ɸղŸ���������أ���");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("����˵��:����������ȱһ��ҩ���ȥ������һ��" + targ + "���ɣ���\n");
		me->set_temp("yao",coun);
	}

void init()
{
	add_action("do_give","give");
}

int do_give(string arg)
{
	object obj, obj2, me, *inv, who;
	string item;
	int amount, i;

	me = this_player();

	if(!arg) return notify_fail("��Ҫ��˭ʲô������\n");

	if( sscanf(arg, "%s to tz", item) == 1 || sscanf(arg, "tz %s", item)==1 );
		else 
			return notify_fail("��Ҫ��˭ʲô������\n");

	if(!objectp(who = present("tang zhong", environment(me))) || !living(who))
		return notify_fail("����û������ˡ�\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("������û������������\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "���ܱ��ֿ����ˡ�\n");
		if( amount < 1 )
			return notify_fail("����������������һ����\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("��û����ô���" + obj->name() + "��\n");
		else 
			if( amount == (int)obj->query_amount() )
				return do_giveto(me, obj2);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_giveto(me, obj2))
					return 1;
				else
				{
					obj->set_amount((int)obj->query_amount() + amount);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_giveto(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("������û������������\n");
	return do_giveto(me, obj);
}

int do_giveto(object me, object obj)
{
	if ( obj->query("id") == "cao yao" && !userp(obj) )
	{
		message_vision("����˵�������������ˣ������������\n", me);
		destruct(obj);
		me->delete_temp("tangmen");
		me->delete_temp("yao");
		me->delete_temp("find");
		return 1;
	}

}

protected void give_yaofen(object me)
	{
	object yaofen;

	if(!me || (environment(me) != environment())
	|| me->query("quest/tangmen_quest/have_yaofen") )
		return;

	guan = new(__DIR__"obj/yaofen");
	guan->move(this_object());
	me->set("quest/tangmen_quest/have_yaofen",1);
	tell_object(me,sprintf("%s���ͷ˵������������ˡ�\n",name()));
	tell_object(me,sprintf("%sת��ҩ��ŵ�ʯ���ﵷ�飬Ȼ����һ��ҩ�������㣬Ȼ��˵����ȥ�����ɡ�\n",name()));
	command(sprintf("give yaofen to %s",me->query("id")));
}