// marry_card.c
// by Find.

#include <ansi.h>

inherit ITEM;

protected string master,m_id,couple,c_id,m_date;
protected mapping m_emote = ([
"love" : ([
	"self" : "����������������$t$n�ˡ�\n",
	"other" : "���$m$N��������������ˡ�\n",
	]),
"hug" : ([
	"self" : "��ӵס���$t$n�������һ�ǣ���á�������á�����\n",
	"other" : "���$m$Nӵס�㣬�����һ�ǣ���á�������á�����\n",
	]),
]);

protected int max_esum = 12, max_long = 200;
protected void add_self(string r,object me,string emote);
protected void add_other(string self,object me,string emote);
protected void add_finish(string other,object me,string emote,string self);

protected mapping query_emote(string verb)
{
	if(!mapp(m_emote) || undefinedp(m_emote[verb]))
		return 0;

	return m_emote[verb];
}

protected string help()
{
	return "
memote -l             �г���ǰ���е� emote
memote -d [emote]     ɾ��һ�� emote
memote [emote]        ����� emote �Ѵ��ھ��г�����
                      ��������ھͱ༭������� emote
\n";
}

void set_master(string m,string id,string cn,string cid,string md)
{ master = m; m_id = id;
  couple = cn, c_id = cid; m_date = md; }

void init_emote()
{
	mapping usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return;

	if(!mapp(usrmap = env->query("marry_emote")) || !sizeof(usrmap))
		return;

	m_emote += usrmap;
}

varargs string name(int raw)
{
	string name = ::name(raw);

	if(stringp(master))
		return master + "��" + couple + name;
	return name;
}

protected string query_long()
{
	if(!m_id || !c_id)
		return "��Ч֤�顣\n";

	return sprintf("
        %s\n\n\
    �����ҳ���������:\n\
       %s(%s)\n\
       %s(%s)\n\
�������ã����ϻ���������������\n\
��׼����Ϊ���ޡ�\n\n\n\
         ����ǩ��
     %s%s\n\n",HIY "��֤���顷" NOR,
	master,capitalize(m_id),
	couple,capitalize(c_id),
	MUD_NAME,m_date);
}

void create()
{
	set_name("��֤����", ({"marry book"}) );

	set("no_get",1);
	set("no_put",1);
	set("no_drop","���֤���鲻�ܶ���,ֻ��ȥ�ٸ������Լ��\n");
	set("no_steal","���Ǳ��˵�֤���飬������������Ҳûʲô�ô���\n");

	set("long",(: query_long :));

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "paper");
	}
}

void init()
{
	if( m_id
	&& environment()
	&& userp(environment())
	&& (environment()->query("id") == m_id) )
	{
		add_action("do_ce","me");
		add_action("do_ct","mt");
		add_action("do_emote","memote");
	}
}

int do_ce(string arg)
{
	object couple_ob,me;
	string tmpstr1, tmpstr2,strm,stro;
	mapping marry,emote;

	me = environment();
	if(!me || me->query("id") != m_id)
		return 0;

	if( !mapp(marry = me->query("marry")) || !sizeof(marry) )
		return notify_fail("��û�а��¡�\n");

	if((string)me->query("gender") != "����")
	{
		tmpstr1 = "����";
		tmpstr2 = "���";
	}

	else
	{
		tmpstr1 = "���";
		tmpstr2 = "����";
	}

	couple_ob = find_player(marry["id"]);

	if( !couple_ob )
		return notify_fail(sprintf("���%s%s�����޷�������������������Ѿ��뿪��Ϸ�ˡ�\n",
			tmpstr2,couple));

	if(!arg)
		return notify_fail("��Ҫ����İ����㷢ʲô���ĸ��飿\n");
	if(!mapp(emote = query_emote(arg)))
		return notify_fail("��û�ж������ emote��\n");

	strm = replace_string(emote["self"],"$t",tmpstr2);
	strm = replace_string(strm,"$n",couple_ob->name(1));
	stro = replace_string(emote["other"],"$m",tmpstr1);
	stro = replace_string(stro,"$N",me->name(1));

	tell_object(me,sprintf(BWHT YEL "��%s" NOR,strm));
	tell_object(couple_ob,sprintf(BWHT YEL "��%s" NOR,stro));
	return 1;
}

int do_ct(string arg)
{
	object couple_ob,me;
	string tmpstr1, tmpstr2;
	mapping marry;

	me = environment();
	if(!me || me->query("id") != m_id)
		return 0;

	if( !mapp(marry = me->query("marry")) || !sizeof(marry) )
		return notify_fail("��û�а��¡�\n");

	if((string)me->query("gender") != "����")
	{
		tmpstr1 = "����";
		tmpstr2 = "���";
	}

	else
	{
		tmpstr1 = "���";
		tmpstr2 = "����";
	}

	couple_ob = find_player(marry["id"]);

	if( !couple_ob )
		return notify_fail(sprintf("���%s%s�����޷�������������������Ѿ��뿪��Ϸ�ˡ�\n",
			tmpstr2,couple));

	if(!arg) arg="...";

	tell_object(me,sprintf(BWHT YEL"���%s%s˵��%s\n"NOR,
		tmpstr2,couple_ob->name(1), arg ));
	tell_object(couple_ob, sprintf(BWHT YEL "%s%s����˵��%s\n"NOR, 
		tmpstr1,me->name(1), arg ));
	return 1;
}

protected string out_all()
{
	string out = "",*key;
	int n;

	n = sizeof(key = keys(m_emote));
	for(int i=0;i<n;i++)
		out += sprintf("EMOTE��\"%s\"
  ����������%s
  �Է�������%s\n",key[i],m_emote[key[i]]["self"],m_emote[key[i]]["other"]);
	return out;
}

int delete_emote(string emote)
{
	mapping usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return 0;

	map_delete(m_emote,emote);
	usrmap = env->query("marry_emote");
	if(mapp(usrmap) && !undefinedp(usrmap[emote]))
	{
		map_delete(usrmap,emote);
		env->set("marry_emote",usrmap);
		env->save();
	}

	return 1;
}

// ��ʾ���е� emote : -l
// ɾ�� emote: -d
// �޲�����ʾ����
// emote: ����� ��ʾ�������ھͱ༭����(������Сд��ĸ 3-10)
int do_emote(string arg)
{
	object me = this_player(),coup;
	string emote;
	int n;

	if(!stringp(arg)
	|| (arg == "") )
	{
		write(help());
		return 1;
	}

	if(arg == "-l") // list all
	{
		me->start_more(out_all());
		return 1;
	}

	if(arg[0..1] == "-d")
	{
		object card;

		if(!sscanf(arg,"-d %s",emote))
			return notify_fail("��Ҫɾ���ĸ� emote ��\n");

		if(undefinedp(m_emote[emote]))
			return notify_fail("��û�ж����������� emote��\n");
		if(emote == "love" || emote == "hug")
			return notify_fail("���ǳ�ʼ���õķ��� emote������ɾ����\n");

		if(!objectp(coup = find_player(c_id)))
			return notify_fail("��İ�������û���ڣ����»���һ�������Ű�ɡ�\n");

		card = present("marry book",coup);
		if(!card)
		{
			card = new(MARRYCARD_OB);
			card->set_master( couple,
				c_id,
				master,
				m_id,
				m_date);
			if(!card->move(coup))
				return notify_fail("ɾ��ʧ�ܡ�\n");
		}
		card->init_emote();
		if(!card->delete_emote(emote))
			return notify_fail("ɾ��ʧ�ܡ�\n");
		tell_object(coup,sprintf(HIY"\n��İ��½�ԭ�е� emote��%s ɾ���ˡ�\n\n"NOR,emote));

		delete_emote(emote);

		write("ok.\n");
		return 1;
	}

	if(!undefinedp(m_emote[arg]))
	{
		printf("\nEMOTE��\"%s\"
  ����������%s
  �Է�������%s\n",arg,m_emote[arg]["self"],m_emote[arg]["other"]);
		return 1;
	}

	if((n=sizeof(arg)) < 3 || n > 10)
		return notify_fail("���� emote ������ 3 �� 10 ��Ӣ��Сд��ĸ��\n");
	for(int i =0; i<n; i++)
		if(arg[i] < 'a' || arg[i] > 'z')
			return notify_fail("���� emote ������ 3 �� 10 ��Ӣ��Сд��ĸ��\n");

	write(sprintf("������ %s ��� emote���Ƿ�Ҫ�༭���룿(y/n)\n",arg));
	input_to((: add_self :),me,arg);
	return 1;
}

protected void add_self(string r,object me,string emote)
{
	if(!stringp(r) || r=="" || r[0] != 'y')
	{
		write("ok.\n");
		return;
	}

	if(sizeof(m_emote) >= max_esum)
	{
		write("Ŀǰ�趨�� emote �Ѿ��ܶ��ˣ������Ҫ�����Ƚ����õ�ɾ����\n");
		return;
	}

	if(!find_player(c_id))
	{
		write("��İ�������û���ڣ����»���һ�������Ű�ɡ�\n");
		return;
	}

	write("����������� emote ʱ*�Լ�*��������Ϣ (q �˳�)��
[$t ��ԶԷ��ĳ�ν��$m �Է�����ĳ�ν��$N ������֣�$n �Է�������]
------------------------------------------------------------------
");
	input_to((: add_other :),me,emote);
}

protected void add_other(string self,object me,string emote)
{
	if(!stringp(self) || self=="" || self[0] == 'q')
	{
		write("ok.\n");
		return;
	}

	if(strlen(self) > max_long)
	{
		write(sprintf("emote �ĳ��Ȳ�Ҫ���� %d �������֡�\n",max_long/2));
		return;
	}

	write("����������� emote ʱ*�Է�*��������Ϣ (q �˳�)��
[$t ��ԶԷ��ĳ�ν��$m �Է�����ĳ�ν��$N ������֣�$n �Է�������]
------------------------------------------------------------------
");
	input_to((: add_finish :),me,emote,self);
}

int add_emote(string self,string other,string emote)
{
	mapping add,usrmap;
	object env;

	if(!(env = environment())
	|| !userp(env)
	|| (env->query("id") != m_id) )
		return 0;

	if(self[<1] != '\n')
		self += "\n";
	if(other[<1] != '\n')
		other += "\n";

	add = ([ "self":self, "other":other]);

	m_emote += ([ emote : add ]);
	usrmap = env->query("marry_emote");
	if(!usrmap)
		usrmap = ([]);
	usrmap += ([ emote : add ]);
	env->set("marry_emote",usrmap);
	env->save();

	return 1;
}

protected void add_finish(string other,object me,string emote,string self)
{
	object coup,card;

	if(!stringp(other) || other=="" || other[0] == 'q')
	{
		write("ok.\n");
		return;
	}

	if(strlen(other) > max_long)
	{
		write(sprintf("emote �ĳ��Ȳ�Ҫ���� %d �������֡�\n",max_long/2));
		return;
	}

	if(!objectp(coup = find_player(c_id)))
	{
		write("��İ�������û���ڣ����»���һ�������Ű�ɡ�\n");
		return;
	}

	card = present("marry book",coup);
	if(!card)
	{
		card = new(MARRYCARD_OB);
		card->set_master( couple,
			c_id,
			master,
			m_id,
			m_date);
		if(!card->move(coup))
		{
			write("���� emote ʧ�ܡ�\n");
			return;
		}
	}
	card->init_emote();
	if(!card->add_emote(self,other,emote))
	{
		write("���� emote ʧ�ܡ�\n");
		return;
	}
	tell_object(coup,sprintf(HIY"\n��İ����¼�����һ��emote��%s\n\n"NOR,emote));
	add_emote(self,other,emote);

	write(sprintf("\nEMOTE��\"%s\"
  ����������%s
  �Է�������%s\n�Ѽ��롣\n",emote,self,other));
}

void owner_is_killed() { destruct(this_object()); }
