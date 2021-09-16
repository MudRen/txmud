// attack.c
// ������ npc ǧ��֮��ȡ�������� bug��
// Modified by Find.

#include <ansi.h>
#include <dbase.h>
#include <origin.h>
#include <skill.h>

#define MAX_OPPONENT	4

static object *enemy = ({});
static string *killer = ({});
static string current_skill = "unarmed";

object *query_enemy() { return enemy; }
string *query_killer() { return killer; }

nomask string query_current_skill()
{ return current_skill; }

nomask void accept_first_kill(object ob)
{
	object *first_kill, *you_first_kill, me;

	if(!ob || !userp(ob) || !userp(me = this_object()))
		return;

	if(arrayp(you_first_kill = ob->query_temp("players_kill_me"))
	&& (member_array(me, you_first_kill) != -1))
	{
		you_first_kill -= ({ me }); you_first_kill -= ({ 0 });
		ob->set_temp("players_kill_me", you_first_kill);
	}

	if(!arrayp(first_kill = query_temp("players_kill_me")) || !sizeof(first_kill))
		first_kill = ({ ob });
	else
	{
		first_kill -= ({ 0 });
		if(member_array(ob, first_kill) == -1)
			first_kill += ({ ob });
	}

	set_temp("players_kill_me", first_kill);
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_fighting(object ob)
{
	if( !ob ) return sizeof(enemy) > 0;

	return member_array(ob, enemy)!=-1;
}

// This function returns 1 if we are fighting anyone (or with ob)
varargs int is_killing(string id)
{
	if( !id ) return sizeof(killer) > 0;

	return member_array(id, killer)!=-1;
}

//This function starts fight between this_object() and ob
varargs nomask void fight_ob(object ob,int flag)
{
	if(!ob || (ob==this_object())) return;

#ifdef WIZARD_FLAG
	if( userp(this_object())
	&& userp(ob)
	&& wizardp(this_object()) != wizardp(ob))
		return;
	if(ob->query_wiz_flag() && userp(this_object()) && !wizardp(this_object()))
		return;
	if(this_object()->query_wiz_flag() && userp(ob) && !wizardp(ob))
		return;
#endif
	set_heart_beat(1);

	if( member_array(ob, enemy) == -1 )
	{
		object *memb;

		enemy += ({ ob });

		if(!flag && (this_object()->in_array() > 1))
		{
			if(this_object()->is_array_member(ob))
				this_object()->query_array_master()->release_array(5);
			else
			{
				memb = this_object()->query_array_member() - ({ this_object() });
				foreach(object body in memb)
				{
					body->fight_ob(ob,1);
					ob->fight_ob(body);
				}
			}
		}
	}
}

// This function starts killing between this_object() and ob
nomask void kill_ob(object ob)
{
	if(!ob || (ob==this_object())) return;

#ifdef WIZARD_FLAG
	if( userp(this_object())
	&& userp(ob)
	&& wizardp(this_object()) != wizardp(ob))
		return;
	if(ob->query_wiz_flag() && userp(this_object()) && !wizardp(this_object()))
		return;
	if(this_object()->query_wiz_flag() && userp(ob) && !wizardp(ob))
		return;
#endif

	if(userp(ob) && userp(this_object()))
	{
		if( (ob->query("age") > PROTECT_AGE)
		&& (query("age") > PROTECT_AGE)
		&& (member_array(ob->query("id"), killer)==-1) )
			killer += ({ ob->query("id") });
	}
	else if( member_array(ob->query("id"), killer)==-1 )
		killer += ({ ob->query("id") });

	if(living(this_object())) /* ���ѵ�ʱ��Ż���ֳ�Ҫɱ�ˡ� Find.*/
		tell_object(ob, HIR "������" + this_object()->name() + "��ɱ���㣡\n" NOR);

	fight_ob(ob);
}

void clean_up_enemy()
{
	if( sizeof(enemy) > 0 )
	{
		for(int i=0; i<sizeof(enemy); i++)
		{
			if( !objectp(enemy[i])
			|| environment(enemy[i])!=environment()
			|| (!living(enemy[i]) && !is_killing(enemy[i]->query("id"))) )
			{
				// by Find.
				if(this_object()->query_temp("last_damage_from") == enemy[i])
					this_object()->delete_temp("last_damage_from");
				enemy[i] = 0;
			}
		}
		enemy -= ({ 0 });
	}
}

// This function checks if the current opponent is available or
// select a new one.
object select_opponent()
{
	int which;

	if( !sizeof(enemy) ) return 0;

	which = random(MAX_OPPONENT);

	return which < sizeof(enemy) ? enemy[which] : enemy[0];
}

// Stop fighting ob.
int remove_enemy(object ob)
{
	if( is_killing(ob->query("id")) ) return 0;

	enemy -= ({ ob });
	// by Find.
	if(this_object()->query_temp("last_damage_from") == ob)
		this_object()->delete_temp("last_damage_from");
	return 1;
}

// Stop killing ob.
int remove_killer(object ob)
{
	if( is_killing(ob->query("id")) )
	{
		killer -= ({ ob->query("id") });
		remove_enemy(ob);
		return 1;
	}

	return remove_enemy(ob);
}

// Stop all fighting, but killer remains.
void remove_all_enemy()
{
	for(int i=0; i<sizeof(enemy); i++)
	{
		// We ask our enemy to stop fight, but not nessessary to confirm
		// if the fight is succeffully stopped, bcz the fight will start
		// again if our enemy keeping call COMBAT_D->fight() on us.
		if( objectp(enemy[i]) )
		{
			enemy[i]->remove_enemy(this_object());
			// by Find.
			if(this_object()->query_temp("last_damage_from") == enemy[i])
				this_object()->delete_temp("last_damage_from");
			enemy[i] = 0;
		}
	}

	enemy = ({});
}

// Stop all fighting and killing.
void remove_all_killer()
{
	killer = ({});
	enemy -= ({ 0 });

	for(int i=0; i<sizeof(enemy); i++)
		if( enemy[i]->remove_killer(this_object()) )
		{
			// by Find.
			if(this_object()->query_temp("last_damage_from") == enemy[i])
				this_object()->delete_temp("last_damage_from");
			enemy[i] = 0;
		}
	enemy -= ({ 0 });
}

// reset_action()
//
// This function serves as a interface of F_ATTACK and wielded, worn objects.
// When the living's fighting action need update, call this function.
//
void reset_action()
/* Modified by Find, ���� "second_actions" ���������ֱ����� action */
{
	object ob;
	string type, skill;

	if( objectp(ob = query_temp("weapon")) && (ob->query("skill_type") != "throwing") )
		type = ob->query("skill_type");
	else
		type = "unarmed";

	if(stringp(skill = query_skill_mapped(type)) )
	{
		set("actions", (: call_other, SKILL_D(skill), "query_action" :) );
		if(current_skill != skill)
		{
			current_skill = skill;
			this_object()->change_skill_status(skill);
		}
		current_skill = skill;
	}
	else
	{
		if( ob && (ob->query("skill_type") != "throwing"))
			set("actions", ob->query("actions",1) );
		else
			set("actions", query("default_actions",1) );

		if(current_skill != type)
		{
			current_skill = type;
			this_object()->change_skill_status(type);
		}
		current_skill = type;

	}

	if( objectp(ob = query_temp("secondary_weapon")) && (ob->query("skill_type") != "throwing"))
	{
		if(ob->query("skill_type") != type) /*�Ƿ�Ϊ��ͬ�ֱ���?*/
		{
			if(stringp(skill = query_skill_mapped(ob->query("skill_type"))))
				set("second_actions",
				(: call_other, SKILL_D(skill), "query_action" :) );
			else
				set("second_actions", ob->query("actions",1));
		}
		else
			set("second_actions",0);
	}

	else
		set("second_actions",0);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) )
	{
		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	}

	else
		return 0;
}

//
// init() - called by MudOS when another object is moved to us.
//
void init()
{
	object ob, me;
	string vendetta_mark;

	// ������
	if(!objectp(ob = this_player())
	|| !living(me = this_object())
	|| (ob == me)
	|| query_temp("netdead")
	|| is_fighting()
	|| (!userp(ob) && !userp(me))
	|| (environment(ob)!=environment())
	|| !living(ob)
	|| ob->is_master()
	|| ob->query_temp("netdead") )
		return;

	if(userp(me)
	&& userp(ob)
	&& (wizardp(me)
	|| wizardp(ob)
	|| (me->query("age") <= PROTECT_AGE)
	|| (ob->query("age") <= PROTECT_AGE) ) )
		return;
	// END ������

	if( userp(ob)
	&& is_killing(ob->query("id"))
	&& !userp(me)
	&& (query("attitude")!="friendly")
	&& (query("attitude")!="peaceful") )	// ���
	{
		COMBAT_D->auto_fight(me, ob, "hatred");
		return;
	}

	else if( stringp(vendetta_mark = query("vendetta_mark"))
	&& ob->query("vendetta/" + vendetta_mark) )
	{
		COMBAT_D->auto_fight(me, ob, "vendetta");
		return;
	}

	else if( userp(ob)
	&& ( (query("attitude")=="aggressive")
	|| (query("attitude")=="killer") ) )	// �Զ�ɱ�˵� npc
	{
		COMBAT_D->auto_fight(me, ob, "aggressive");
		return;
	}

	// ɱ��
	else if( random((int)query("bellicosity") / 40) > (int)query("con") )
	{
		COMBAT_D->auto_fight(me, ob, "berserk");
		return;
	} 
}
