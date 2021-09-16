// user.c
// Modified by Find.

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_BUSINESS;
inherit F_SELF;

nosave int last_age_set;
nosave int been_wizard_guard = 0;
// �������õ�
protected int credit_point = 0;

void add_credit_point(int n)
{
	if(!intp(n))
		return;

	credit_point += n;
}

int query_credit_point() { return credit_point; }

nomask void set_wizard_guard_flag(int flag)
{
	if( !previous_object() || (geteuid(previous_object()) != ROOT_UID) || !intp(flag) )
		return;
	been_wizard_guard = flag;
}

nomask int in_wizard_guard() { return been_wizard_guard?1:0; }

void create()
{
	::create();
	set_name("ʹ�������", ({ "user object", "user", "object" }) );
        this_object()->init_zhen();
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�ն˻���̬�趨Ϊ " + term_type + "��\n", this_object());
}

void reset()
{
	if( (int)query("potential") - (int)query("learned_points") < 100 )
		add("potential", 1);
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid(this_object());
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	refresh_all_my_ob();
	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}

protected void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			if(!query_temp("netdead"))
				return;

			if(!living(this_object()))
			{
				call_out("user_dump",5,type);
				return;
			}
			tell_room(environment(), name() + "���߳�ʱ���Զ��˳�������硣\n",
				filter_array( all_inventory(environment()), "filter_invisible",
				this_object(),this_object()) );

			save();
			command("quit 68#@");
			break;
		case DUMP_IDLE:
			if(wizardp(this_object()))
				break;
			else if(!living(this_object()))
			{
				call_out("user_dump",5,type);
				return;
			}
			tell_object( this_object(), "�Բ������Ѿ��������� " 
				+ IDLE_TIMEOUT/60 + " �����ˣ����´�������\n");
			tell_room(environment(),"һ��紵�����������е�" + name()
				+ "��Ϊһ�ѷɻң���ʧ�ˡ�\n",
				filter_array( all_inventory(environment()), "filter_invisible",
				this_object(),this_object()) );

			save();
			command("quit");
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
protected void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();

        set_temp("netdead", time());
	if( userp(this_object()) ) {
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
		tell_room(environment(), name() + "�����ˡ�\n",
			filter_array( all_inventory(environment()), "filter_invisible",
			this_object(),this_object()) );
		LOGIN_D->report_netdead(this_object());
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "����������ϡ�\n");
}

// added by Find. ����״������ҵ�Ӱ��.
void weather_effect(string weather)
{
	mapping cloth;
	int i,con,flag = 0,old;
	string c_weather,*what,*can_cover_body;

	if(!environment(this_object())->query("outdoors"))
		return;

	switch ( weather )
	{
	case "snow":
		c_weather = "��ѩ";
		break;
	case "wind":
		c_weather = "���";
		break;
	case "cloudy":
		c_weather = "����";
		break;
	}

	con = this_object()->query("con");
	can_cover_body = ({ "cloth", "armor", "surcoat" });

	if( mapp(cloth = this_object()->query_temp("armor")) )
	{
		what = keys(cloth);
		if( !sizeof(what) && random(con) <= 20 )
		{
			message_vision("$N����������" + c_weather + 
				"���Ĵ��ε���"+((old = this_object()->query_condition("ganmao"))?
				"��ð�ּ����ˡ�\n":"�����ظ�ð��\n"),this_object());
			this_object()->apply_condition("ganmao", old+8+random(6));
			return;
		}

		for(i=0;i<sizeof(what);i++)
		{
			if(flag) break;
			if(member_array(cloth[what[i]]->query("armor_type"),can_cover_body) == -1)
				continue;
			else flag = 1;
		}

		if(flag) return;

		else if(random(con) <= 20)
		{
			message_vision("$N�²�������" + c_weather + 
				"���Ĵ��ε���"+((old = this_object()->query_condition("ganmao"))?
				"��ð�ּ����ˡ�\n":"�����ظ�ð��\n"),this_object());
			this_object()->apply_condition("ganmao", old+8+random(6));
			return;
		}
		return;
	}

	else if(random(con) <= 20)
	{
		message_vision("$N����������" + c_weather + 
			"���Ĵ��ε���"+((old = this_object()->query_condition("ganmao"))?
			"��ð�ּ����ˡ�\n":"�����ظ�ð��\n"),this_object());
		this_object()->apply_condition("ganmao", old+8+random(6));
		return;
	}
}
// end.

nomask mixed set(string prop, mixed data)
{
	if( (prop == "id") && (geteuid(previous_object()) != ROOT_UID) )
		return 0;  /* user's id can only be set by SYSTEM. by Find. */

	else if(member_array(prop,attribute) != -1)
	{
		if(!sscanf(file_name(previous_object()),"/adm/%*s"))
			return 0;
		else
			return ::set(prop, data);
	}

	if( wizardp(this_object())
	|| ( previous_object()
	&& ( sscanf(file_name(previous_object()),"/cmds/%*s")
	|| (geteuid(previous_object()) == ROOT_UID) ) ) )
		return ::set(prop, data);
	
	if( ( previous_object()
	&& ( previous_object()->query_wiz_flag()
	|| sscanf(file_name(previous_object()),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
	{
		sys_log("set",sprintf("(%s) set (%s) prop:%s, data:%O, pre_obj:%s\n",
			previous_object()?geteuid(previous_object()):geteuid(this_player(1)),
			geteuid(this_object()),prop,data,
			previous_object()?file_name(previous_object()):"none"));
	}

	return ::set(prop, data);
}

nomask mixed set_temp(string prop, mixed data)
{
	if((prop == "link_ob"))
	{
		if(!previous_object() || (geteuid(previous_object()) != ROOT_UID) )
			return 0;
		else
			return ::set_temp(prop, data);
	}

	if( wizardp(this_object())
	|| ( previous_object()
	&& ( sscanf(file_name(previous_object()),"/cmds/%*s")
	|| (geteuid(previous_object()) == ROOT_UID) ) ) )
		return ::set_temp(prop, data);
	
	if( ( previous_object()
	&& ( previous_object()->query_wiz_flag()
	|| sscanf(file_name(previous_object()),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
	{
		sys_log("set",sprintf("(%s) set_temp (%s) prop:%s, data:%O, pre_obj:%s\n",
			previous_object()?geteuid(previous_object()):geteuid(this_player(1)),
			geteuid(this_object()),prop,data,
			previous_object()?file_name(previous_object()):"none"));
	}

	return ::set_temp(prop, data);
}

nomask int delete(string prop)
{
	if( wizardp(this_object())
	|| ( previous_object()
	&& ( sscanf(file_name(previous_object()),"/cmds/%*s")
	|| (geteuid(previous_object()) == ROOT_UID) ) ) )
		return ::delete(prop);
	
	if( ( previous_object()
	&& ( previous_object()->query_wiz_flag()
	|| sscanf(file_name(previous_object()),WIZ_DIR"%*s") ) )
	|| (this_player(1) && wizardp(this_player(1))) )
	{
		sys_log("delete",sprintf("(%s) delete (%s) prop:%s, pre_obj:%s\n",
			geteuid(this_player(1)),geteuid(this_object()),prop,
			previous_object()?file_name(previous_object()):"none"));
	}

	return ::delete(prop);
}

int filter_invisible(object ob,object user)
{
	if(ob == user)
		return 1;
	if( !userp(ob) )
		return 1;
	if( !ob->visible(user) )
		return 1;
	return 0;
}

void guest_count()
{
	if(!previous_object() || (geteuid(previous_object()) != ROOT_UID))
		return;

	call_out("do_guest_leave",600);
}

protected void do_guest_leave()
{
	tell_object(this_object(),"\n���ι�ʱ���ѵ���������Ҫע����ʽ�˺ţ���ʹ������ ID ������Ϸ��\n\n");
	command("quit");
}

mapping query_skills()	// by Find.
{
	if( previous_object()
	&& (previous_object() != this_object())
	&& (geteuid(previous_object()) != ROOT_UID) )
		return copy(::query_skills());
	else
		return ::query_skills();
}
