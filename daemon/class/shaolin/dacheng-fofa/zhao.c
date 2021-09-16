// zhao.c

#include <ansi.h>

int conjure(object me)
{
	mapping where,select = ([]);
	object env;
	int ski,val,day,time;

	if(!objectp(me || (me->query("class") != "shaolin")))
		return 0;

	if( (ski = me->query_skill("dacheng-fofa",1)) < 100)
		return notify_fail("��ġ���˷𷨡���Ϊ���㡣�޷�ʩչ���������ۡ���\n");

	if(me->query("atman") < 500)
		return notify_fail("����������㡣�޷�ʩչ���������ۡ���\n");

	if(!(env = environment(me))
	|| !sscanf(file_name(env),"/d/%*s")
	|| !env->is_room()
	|| !env->query("outdoors")
	|| virtualp(env)
	|| (env->is_player_home() && (me->query("id") != env->query("master_id")))
	|| env->query("no_memory"))
		return notify_fail("�˵��޷�ʩչ���������ۡ���\n");

	if(ski < 150)
	{
		val = 3;
		day = 60;
	}
	else if(ski < 200)
	{
		val = 4;
		day = 90;
	}
	else
	{
		val = 5;
		day = 180;
	}

	if(!mapp(where = me->query("family/fofa")) || !sizeof(where))
	{
		me->add("atman",-500);
		tell_object(me,HIB"\n�㱧Ԫ��һ��ʩչ���������ۡ���һ˿���է�����������Χ������\n\n"NOR);
		tell_room(env,sprintf(HIB"\n%s˫�ֺ�ʮ��˫�۽��գ�ͷ���ó�һ������������Χ������\n\n"NOR,me->name()),({me}));
		me->start_busy(10);
		call_out("do_memory",5,me,env,day);
		return 1;
	}

	time = time();

	foreach(string fname,int t in where)
	{
		object room;
		string f;

		if( (t - time) <= 0 )
		{
			me->delete("family/fofa/"+fname);
			continue;
		}

		f = replace_string(fname,"&","/");
		room = find_object(f);
		if(!room)
			room = load_object(f);
		if(!room)
		{
			me->delete("family/fofa/"+fname);
			continue;
		}
		select += ([ fname : room->query("short") ]);
	}

	if(mapp(where = me->query("family/fofa")) && (sizeof(where) >= val))
	{
		string out = "",*ws = keys(select);

		tell_object(me,"��ġ��������ۡ��޷��ټ������ĵط��ˡ�\n��ѡ��һ�����õĵط�ȥ�����䣺(q �˳�)\n");
		for(int i=0;i<sizeof(ws);i++)
			out += sprintf("%d. ��%s��\n",(i+1),select[ws[i]]);
		tell_object(me,out);
		input_to("do_dest",me,select,env,day);
		return 1;
	}

	me->add("atman",-500);
	tell_object(me,HIB"\n�㱧Ԫ��ڤ��ʩչ���������ۡ���һ˿���է�����������Χ������\n\n"NOR);
	tell_room(env,sprintf(HIB"\n%s˫�ֺ�ʮ��˫�۽��գ�ͷ���ó�һ������������Χ������\n\n"NOR,me->name()),({me}));
	me->start_busy(10);
	call_out("do_memory",5,me,env,day);
	return 1;
}

private void do_dest(string num,object me,mapping select,object env,int day)
{
	int n;

	if(!objectp(me) || !objectp(env) || (num[0] == 'q'))
		return;

	if(!sscanf(num,"%d",n))
	{
		tell_object(me,"ѡ�����\n");
		return;
	}

	if( (n < 1) || (n > sizeof(select)) )
	{
		tell_object(me,"ѡ�����\n");
		return;
	}

	n--;

	me->delete(sprintf("family/fofa/%s",keys(select)[n]));

	me->add("atman",-500);
	tell_object(me,HIB"\n�㱧Ԫ��ڤ��ʩչ���������ۡ���һ˿���է�����������Χ������\n\n"NOR);
	tell_room(env,sprintf(HIB"\n%s˫�ֺ�ʮ��˫�۽��գ�ͷ���ó�һ������������Χ������\n\n"NOR,me->name()),({me}));
	me->start_busy(10);
	call_out("do_memory",5,me,env,day);
}

private void do_memory(object me,object env,int day)
{
	string f;

	if(!objectp(me) || !objectp(env))
		return;

	if(environment(me) != env)
	{
		tell_object(me,"��ġ��������ۡ�ʧ���ˡ�\n");
		me->stop_busy();
		return;
	}

	f = base_name(env);
	f = replace_string(f,"/","&");

	me->set(sprintf("family/fofa/%s",f),(time()+day*1440));

	tell_object(me,HIB"\n��Χ�ľ�����������ӳ������ķ��ۣ���ʩ����ϣ��о��ǳ�ƣ�͡�\n\n"NOR);
	tell_room(env,sprintf(HIB"���⻺������ʧ��%sƣ����������˫�ۡ�����\n\n"NOR,me->name()),({me}));

	if(me->query("gin") > 10)
		me->set("gin",10);

	me->stop_busy();
}
