// litang.c

#include <ansi.h>

inherit NPC;

object master,working;
int time,money,bai;

int open_heart_beat() { return 1; }

private int do_check(string msg)
{
	object mp;

	if(!objectp(master)
	|| !objectp(working)
	|| (environment(master) != environment())
	|| (environment(working) != environment()) )
	{
		if(stringp(msg))
			message_vision(msg,this_object());
		if(master)
			environment()->can_out(master);
		if(working)
			environment()->can_out(working);
		mp = present("mei po",environment());
		if(objectp(mp))
			mp->fail();
		call_out("leave",2);
		return 0;
	}
	return 1;
}

void create()
{
	set_name("������", ({ "he shi lao" }));
	set("title","���ù�");
	set("long", "����һλ������ֵ��������ӣ������ȴ��
��һλ��С�ĳ�͢���١�\n");
	set("gender","����");

	set("age",45);
	set("con",20);
	set("str",20);
	set(NO_KILL, 1);

	set("combat_exp",1500);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

void begin_hunli(object m,object w)
{
	master = m; working = w;

	if(!do_check("$N����üͷ˵�����˶�û��������������ʲô�����֣�\n"))
		return;

	master->delete_temp("marry_bai");
	working->delete_temp("marry_bai");
	message_vision("\n$N�����š�������һ��ɤ�ӣ�����һ��ͷ��\n",this_object());
	call_out("do_say",2);
}

private void do_say()
{
	message_vision("\n$N�����Ƶ�˵���������á������С������������Σ�ִ���񲿡�������
	���ջ�������Ҳ�ɱ����á������ƹܡ��������񲿹涨��������
	ÿ�����������񲿽��ɡ�����ʮ���ƽ𡣡��������ѡ�������
	���ڡ������Ƚ�Ǯ�ɣ�\n",this_object());

	money = 1; time = time();
}

private void leave()
{
	if(environment())
		message_vision("$N���ŷ������˳�ȥ��\n",this_object());
	destruct(this_object());
}

int accept_object(object me, object ob)
{
	if( !money
	|| ((me != master)
	&& (me!= working)) )
		return 0;

	if(!is_money(ob))
	{
		message_vision("$N��$n��˵�����������ѣ�����ô���£�\n",this_object(),me);
		return 0;
	}

	if(ob->value() < 100000)
	{
		message_vision("$N��$n��˵����������ʮ���ƽ����ǳ�͢�涨�ģ�\n",this_object(),me);
		return 0;
	}

	money = 0;
	call_out("do_begin",2);
	return 1;
}

int heal_up()
{
	int t = time();

	if(bai)
	{
		if((find_call_out("on_bai") != -1) || (find_call_out("finish_bai") != -1))
			return 0;
		if(!do_check("$N˵������ʽ�����������˾����ˣ��⻹��ʲô�飡���񻰣�\n"))
			return 0;
		if(t - time < 20)
			return 1;
		if(master->query_temp("marry_bai") != bai)
			tell_object(master,"�����϶���˵��������(koubai)ѽ���������黹��ץ����\n");
		if(working->query_temp("marry_bai") != bai)
			tell_object(working,"�����϶���˵��������(koubai)ѽ���������黹��ץ����\n");
		if(t - time > 40)
		{
			object mp;

			message_vision("\n$NĿ����˵������������ĥĥ���ģ��ҿ��ǲ������ˣ����ˣ�����ظ���\n\n",this_object());
			call_out("leave",2);
			environment()->can_out(master); environment()->can_out(working);
			mp = present("mei po",environment());
			if(objectp(mp))
				mp->fail();
			return 0;
		}
		return ::heal_up();
	}

	if(!money)
		return ::heal_up();

	if(!do_check("$N������˵������ô��Ϊ�˼����������˾����ˣ����֣�\n"))
		return 0;

	if( t - time > 40 )
	{
		message_vision("\n$N������˵������ô�������Ѷ�����ò���������ʮ����
	��ֵ�Ļ��ҿ�����Ҳ�գ�\n",this_object());
		call_out("leave",2);
		return 0;
	}

	message_vision("\n$N������˵������ô���¡������Ͻ����������ѡ��������ú�Ϊ�������ֻ���.\n",this_object());
	return ::heal_up();
}

private void do_begin()
{
	if(!do_check("$N˵������ô����Ǯ���ܣ��⻹��ʲô�飡\n"))
		return;

	message_vision("\n$N���̻���һ��Ц��˵�����úá�����λ�ɲ�Ůò����������֮�͡�
	�����ǻƵ����գ��˻��䣡��;�����ʽ�ɣ�\n\n",this_object());

	call_out("on_bai",2);
}

private void on_bai()
{
	if(!do_check("$N˵������ʽ�������о��ܣ��⻹��ʲô�飡\n"))
		return;

	if(bai <= 0)
		bai = 0;

	bai++; time = time();

	switch(bai)
	{
		case 1:
		message_vision(sprintf("$N֣��˵���������ҳ�������������%s��%s�������н����񣬱�����
	����������͢���������Զ�׼�����ֻ��񡣡���������

һ��������(koubai)�������졣�����ء�����������\n\n",master->name(),working->name()),this_object());
			return;
		case 2:
		message_vision("$N���ͷ˵����
����������(koubai)���������������֡������ˡ�����������\n\n",this_object());
			return;
		case 3:
		message_vision("$N���ͷ˵����
�򡣡����ޡ������ԡ�������(koubai)������������\n\n",this_object());
			return;
	}
}

void init()
{
	add_action("do_bai","koubai");
}

int do_bai()
{
	object me = this_player();

	if(!bai || ( (me!= master) && (me != working)))
		return 0;

	if(me->query_temp("marry_bai") == bai)
	{
		write(name()+"����һ��˵�����Ұ�ʲô�����Һ������£�\n");
		return 1;
	}

	if(!do_check("$N˵��������û�������˾����ˣ�̫�����ˣ��ߣ�\n"))
	{
		bai = 0;
		return 1;
	}

	switch (bai)
	{
		case 1:
			me->start_busy(2);
			message_vision("\n$N���������ĳ��Ź�������ġ��Ϻ͡����ɰ�����ȥ��
����˵������л�ϲԴ����������Ե��\n\n",me);
			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("on_bai",3);
			return 1;
		case 2:
			me->start_busy(2);
			message_vision("\n$N���������ĳ������ùٺ����ϰ�����ȥ��
����˵������л��͢��׼����л�ʹ������֡�\n\n",me);
			message_vision("$NЦ���еĵ��˵�ͷ˵������˵����˵������\n");
			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("on_bai",3);
			return 1;
		case 3:
			me->start_busy(2);
			if(me->query("gender") == "����")
				message_vision(sprintf("\n$N����$n������ȥ��˵����%sĳ�˽�����Ȣ%sΪ�ޣ��������ң�
����ϸ���۰����������ơ�\n\n",me->name()[0..1],working->name()),me,working);
			else
				message_vision("\n$N����$n������ȥ��˵����СŮ�����������У����๫
����ϧ��ʼ����һ��\n\n",me,master);

			me->set_temp("marry_bai",bai);
			if( (master->query_temp("marry_bai") == bai)
			&& (working->query_temp("marry_bai") == bai) )
				call_out("finish_bai",5);
			return 1;
	}
}

private void finish_bai()
{
	mapping mm,mw;
	object mp = present("mei po",environment()),mcard;
	int y,m,d;
	string date;

	bai = 0;

	if(!do_check("$N˵��������û�������˾����ˣ�̫�����ˣ��ߣ�\n"))
		return;

	message_vision("$NЦ�Ǻǵ�˵����
�񡣡����������ɡ���������������\n\n",this_object());
	message_vision("$N˵����ף��λ�����మ����ͷ���ϣ�\n\n",this_object());

	if(!mp)
	{
		mp = new(__DIR__"meipo");
		mp->move(environment());
	}

	message_vision("$N����ǰЦ������˵������ϲ����ϲ��\n\n",mp);

	message_vision("$N��������֤����ϸ��÷ֱ𽻸���λ���ˡ�\n\n",this_object());

	y = query_year();
	m = query_month();
	d = query_day_in_month();

	date = sprintf("����%s��%s��%s��",chinese_number(y),chinese_number(m),chinese_number(d));

	mm = allocate_mapping(3);
	mw = allocate_mapping(3);

	mm["id"] = working->query("id");
	mm["name"] = working->query("name");
	mm["date"] = date;

	mw["id"] = master->query("id");
	mw["name"] = master->query("name");
	mw["date"] = date;

	master->set("marry",mm); master->save();
	working->set("marry",mw); working->save();

	mcard = new(MARRYCARD_OB);
	mcard->set_master( master->name(),
		geteuid(master),
		mm["name"],
		mm["id"],
		mm["date"]);
	mcard->move(master);

	mcard = new(MARRYCARD_OB);
	mcard->set_master( working->name(),
		geteuid(working),
		mw["name"],
		mw["id"],
		mw["date"]);
	mcard->move(working);

	CHANNEL_D->do_channel( this_object(), "guanfu",
		sprintf("����͢������׼�������֣�%s��%s��Ϊ���ޡ�\n",
		master->name(),working->name()));

	NEWS_D->add_news_item( sprintf(HIM"%s(%s) �� %s(%s) �ɲ�Ůò���������ã�
����͢������׼�������֣�ϲ������\n"NOR,
		master->query("name"),capitalize(master->query("id")),
		working->query("name"),capitalize(working->query("id")) ),"p", 1);

	message_vision("$N˵����ף��λ�����మ����ͷ���ϣ�
	����ѽ������ظ���\n\n",this_object());

	environment()->can_out(master); environment()->can_out(working);
	call_out("leave",2);
	mp->finish_yishi();
}
