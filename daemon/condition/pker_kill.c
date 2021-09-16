// pker_kill.c
// create by find.

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

protected void begin_kill(object me);

int update_condition(object me, int duration)
{
	object *obj;
	int i;

	if(me->is_ghost())
		return CND_STOP;

//如所处环境禁止战斗则等待。
	if( !environment(me) || environment(me)->query(SAFE_ENV) )
	{
		if(me->query_temp("newlogin"))
			me->set_temp("escape_kill",1);
		return CND_NO_CHANGE;
	}

//符合围剿条件，开始围剿。
	if( me->query("is_pker") )
	{
		me->delete("is_pker");
		me->set("begin_kill",1);
		begin_kill(me);
		return CND_NO_CHANGE;
	}

// 是否都杀死了？都杀死就返回.
	if( (me->query("guanfu_weijiao") == ({}) ) && me->query("begin_kill"))
	{
		me->delete("guanfu_weijiao");
		me->delete("begin_kill");
		return CND_STOP;
	}

// 是否被围剿中间 quit 逃脱？是则重新开始围剿。
	if(me->query_temp("newlogin") || me->query_temp("escape_kill"))
	{
		me->delete_temp("newlogin");
		me->delete_temp("escape_kill");
		begin_kill(me);
		return CND_NO_CHANGE;
	}

// 是否在战斗？或脱离环境？
	obj = me->query("guanfu_weijiao");
	for( i=0; i<sizeof(obj); i++ )
	{
		if(!obj[i])
			continue;
		if( obj[i]->is_fighting() )
			continue;
		if( !living(obj[i]) || obj[i]->query_temp("unconcious") )
			continue;
		if( (environment(obj[i]) != environment(me)) && !environment(me)->query(SAFE_ENV) )
		{
			if( environment(obj[i]) )
				tell_object(environment(obj[i]),obj[i]->name()+"走了。\n");
			obj[i]->move( environment(me) );
			tell_object(environment(me),obj[i]->name()+"走了过来。\n");
			obj[i]->kill_ob(me);
			me->kill_ob(obj[i]);
		}
		else
		{
			obj[i]->kill_ob(me);
			me->kill_ob(obj[i]);
		}
	}

	return CND_NO_CHANGE;
}

protected void begin_kill(object me)
{
	object obj, *guanjun = ({});
	seteuid(getuid());

	obj = new("/obj/npc/touling");
		obj->set_sks(me);
		obj->move(environment(me));
		tell_object(environment(me),obj->name()+"走了过来。\n");
		tell_object(me,obj->name()+"冲你喊道：光天化日之下敢连续作案，不怕王法了！\n");
		obj->set_leader(me);
		obj->set("kill",me);
		obj->kill_ob(me);
		me->kill_ob(obj);
		guanjun += ({obj});
	obj = new("/obj/npc/wushi");
		obj->set_sks(me);
		obj->move(environment(me));
		tell_object(environment(me),obj->name()+"走了过来。\n");
		obj->set_leader(me);
		obj->set("kill",me);
		obj->kill_ob(me);
		me->kill_ob(obj);
		guanjun += ({obj});
	obj = new("/obj/npc/wushi");
		obj->set_sks(me);
		obj->move(environment(me));
		tell_object(environment(me),obj->name()+"走了过来。\n");
		obj->set_leader(me);
		obj->set("kill",me);
		obj->kill_ob(me);
		me->kill_ob(obj);
		guanjun += ({obj});
	obj = new("/obj/npc/wushi");
		obj->set_sks(me);
		obj->move(environment(me));
		tell_object(environment(me),obj->name()+"走了过来。\n");
		obj->set_leader(me);
		obj->set("kill",me);
		obj->kill_ob(me);
		me->kill_ob(obj);
		guanjun += ({obj});
	me->set("guanfu_weijiao",guanjun);
}
