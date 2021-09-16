// char.c
// Modified by Find.

#pragma save_binary

#include <action.h>
#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <dbase.h>
#include <move.h>
#include <name.h>
#include <skill.h>
#include <team.h>
#include <user.h>

inherit F_ACTION;
inherit F_ALIAS;
inherit F_APPRENTICE;
inherit F_ATTACK;
inherit F_ATTRIBUTE;
inherit F_COMMAND;
inherit F_CONDITION;
inherit F_DAMAGE;
inherit F_DBASE;
inherit F_EDIT;
//inherit F_FINANCE;
inherit F_MESSAGE;
inherit F_MORE;
inherit F_MOVE;
inherit F_NAME;
inherit F_SKILL;
inherit F_TEAM;
inherit F_BANGHUI;
inherit F_ENCODING;     // added for encode.


// Use a tick with longer period than heart beat to save cpu's work
static int tick;

void create()
{
	seteuid(0); // so LOGIN_D can export uid to us
}

// Use this function to identify if an object is a character.
int is_character() { return 1; }

// setup: used to configure attributes that aren't known by this_object()
// at create() time such as living_name (and so can't be done in create()).
void setup()
{
	seteuid(getuid(this_object()));

	CHAR_D->setup_char( this_object() );

	if(userp(this_object()) || this_object()->open_heart_beat())
		set_heart_beat(1);

	tick = 5 + random(10);
	enable_player();
}

void heart_beat()
{
	int wimpy_ratio, cnd_flag;
	mapping my;
	//object *ob;

	my = query_entire_dbase();

	// If we are dying because of mortal wounds?
	if( my["eff_kee"] < 0 || my["eff_sen"] < 0 || my["eff_gin"] < 0)
	{
		die();
		return;
	}

	// If we're dying or falling unconcious?
	if( my["kee"] < 0 || my["sen"] < 0 || my["gin"] < 0)
	{
		if( !living(this_object()) ) die();
		else unconcious();
		return;
	}

	continue_perform_busy();

	// Do attack if we are fighting.
	if( is_busy() )
	{
		if(is_fighting())
			tell_object(this_object(),"\n--->>����һ������û����ɣ�ʧȥһ�ν������ᡣ\n");
		continue_action();
		return;
	}

	else
	{
		// Is it time to flee?
		if( is_fighting()
		&& intp(wimpy_ratio = (int)query("env/wimpy"))
		&& wimpy_ratio > 0
		&& ( my["kee"] * 100 / my["max_kee"] <= wimpy_ratio
		|| my["sen"] * 100 / my["max_sen"] <= wimpy_ratio
		|| my["gin"] * 100 / my["max_gin"] <= wimpy_ratio) )
			GO_CMD->do_flee(this_object());
		// Do attack or clean up enemy if we have fleed.
		else	/* ����Ӧ��ռһ������,ͬһʱ���Ȼ��������,��û������. by Find.*/
			attack();
	}

	if( !userp(this_object()) )
	{
		this_object()->chat();
		// chat() may do anything -- include destruct(this_object())
		if( !this_object() ) return;	
	}

	if( tick--  ) return;
	else tick = 5 + random(10);

	cnd_flag = update_condition();

/*
	// ���䲻��������ҽ϶����Ϸ
	// CPU �˷Ѽ���������ķ�������
	// Find.
	if( ((cnd_flag & CND_NO_HEAL_UP) || !heal_up())
	&& !is_fighting() 
	&& !interactive(this_object()))
	{
		if( environment() )
			ob = filter_array(all_inventory(environment()) - ({this_object()}),(: interactive($1) :) );
		if( !ob || !sizeof(ob) )
			set_heart_beat(0);
	}
*/
        heal_up();
	update_all_limb_damage();

	if( !interactive(this_object()) ) return;

	this_object()->update_age();

	if(query_idle(this_object()) > IDLE_TIMEOUT)
		this_object()->user_dump(DUMP_IDLE);
}

// Modified by Find.
int visible(object ob)
{
	int lvl;

	lvl = wiz_level(this_object());

	if(lvl == wiz_level("(admin)"))
		return 1;

	if( lvl > wiz_level(ob) ) return 1;

	if(ob->query("env/invisibility"))
		return (ob == this_object())?1:0;

	if( ob->is_ghost() )
	{
		if( is_ghost() ) return 1;
		if( query_temp("apply/astral_vision") ) return 1;
		if(wizardp(this_object())) return 1;
		return 0;
	}
	return 1;
}
