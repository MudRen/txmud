// /obj/user/login.c
// Modified by Find.

#include <login.h>

#include <dbase.h>

inherit F_DBASE;
inherit F_SAVE;
inherit F_ENCODING;	// added for encode.

void logon()
{
	call_out( "time_out", LOGIN_TIMEOUT );
	LOGIN_D->logon( this_object() );
}

// Don't destruct(this_object()) in the net_dead() interactive apply or
// there'll be error message: Double call to remove_interactive()
void net_dead()
{
	remove_call_out("time_out");
	call_out( "time_out", 1 );
}

void time_out()
{
	object user;

	if( objectp(user = query_temp("body_ob")) )
	{
		if(environment(user))
			return;
		if(interactive(user))
			return;
	}

	if( interactive(this_object()) )
		write("���������߽���������ʱ��̫���ˣ��´���������ɡ�\n");
	if(objectp(user))
		destruct(user);
	destruct(this_object());
}

// This is used by F_SAVE to determinethe file name to save our data.
string query_save_file()
{
	string id;

	id = query("id", 1);
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "login/%c/%s", id[0], id);
}

void receive_message(string type, string str)
{
	if( type!= "write" ) return;

#ifdef GB_AND_BIG5
	str = CONVERT_D->output(str,this_object()); // added for encode.
#endif

	receive(str);
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
}

nomask mixed set(string prop, mixed data)
{
        // added by Find. for (sima liang) to change player's name.
        if( (prop == "name")
	&& (previous_object()->query("id") == "sima liang"))
                return ::set("name",data);

	if( geteuid(previous_object()) != ROOT_UID ) return 0;
		return ::set(prop, data);
}

nomask mapping query_entire_dbase()
{
	return 0;
}

nomask mapping query_entire_temp_dbase()
{
	return 0;
}

nomask mixed set_temp(string prop, mixed data)
{
	if(( prop == "body_ob")
	&& (!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)) )
		return 0;
	return ::set_temp(prop, data);
}

nomask varargs mixed query(string prop, int raw)
{
	if(( prop == "password")
	&& (!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)) )
		return 0;

	return ::query(prop,raw);
}
