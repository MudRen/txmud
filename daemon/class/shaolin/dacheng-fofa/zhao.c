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
		return notify_fail("你的『大乘佛法』修为不足。无法施展『空明法眼』。\n");

	if(me->query("atman") < 500)
		return notify_fail("你的灵力不足。无法施展『空明法眼』。\n");

	if(!(env = environment(me))
	|| !sscanf(file_name(env),"/d/%*s")
	|| !env->is_room()
	|| !env->query("outdoors")
	|| virtualp(env)
	|| (env->is_player_home() && (me->query("id") != env->query("master_id")))
	|| env->query("no_memory"))
		return notify_fail("此地无法施展『空明法眼』。\n");

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
		tell_object(me,HIB"\n你抱元守一，施展『空明法眼』，一丝灵光乍起，罩向你的周围。。。\n\n"NOR);
		tell_room(env,sprintf(HIB"\n%s双手合十，双眼紧闭，头顶幻出一道蓝光罩向周围。。。\n\n"NOR,me->name()),({me}));
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

		tell_object(me,"你的『空明法眼』无法再记忆更多的地方了。\n请选择一个无用的地方去除记忆：(q 退出)\n");
		for(int i=0;i<sizeof(ws);i++)
			out += sprintf("%d. 【%s】\n",(i+1),select[ws[i]]);
		tell_object(me,out);
		input_to("do_dest",me,select,env,day);
		return 1;
	}

	me->add("atman",-500);
	tell_object(me,HIB"\n你抱元守冥，施展『空明法眼』，一丝灵光乍起，罩向你的周围。。。\n\n"NOR);
	tell_room(env,sprintf(HIB"\n%s双手合十，双眼紧闭，头顶幻出一道蓝光罩向周围。。。\n\n"NOR,me->name()),({me}));
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
		tell_object(me,"选择错误。\n");
		return;
	}

	if( (n < 1) || (n > sizeof(select)) )
	{
		tell_object(me,"选择错误。\n");
		return;
	}

	n--;

	me->delete(sprintf("family/fofa/%s",keys(select)[n]));

	me->add("atman",-500);
	tell_object(me,HIB"\n你抱元守冥，施展『空明法眼』，一丝灵光乍起，罩向你的周围。。。\n\n"NOR);
	tell_room(env,sprintf(HIB"\n%s双手合十，双眼紧闭，头顶幻出一道蓝光罩向周围。。。\n\n"NOR,me->name()),({me}));
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
		tell_object(me,"你的『空明法眼』失败了。\n");
		me->stop_busy();
		return;
	}

	f = base_name(env);
	f = replace_string(f,"/","&");

	me->set(sprintf("family/fofa/%s",f),(time()+day*1440));

	tell_object(me,HIB"\n周围的景象已清晰的映入了你的法眼，你施法完毕，感觉非常疲劳。\n\n"NOR);
	tell_room(env,sprintf(HIB"蓝光缓缓的消失，%s疲惫地睁开了双眼。。。\n\n"NOR,me->name()),({me}));

	if(me->query("gin") > 10)
		me->set("gin",10);

	me->stop_busy();
}
