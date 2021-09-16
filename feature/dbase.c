// dbase.c
// Modified by Find.

#include <function.h>
#include <dbase.h>

#ifdef WIZARD_FLAG
inherit F_FLAG;
#endif

static string *attribute = ({"str","int","con","cor","per","kar"});

static mapping improve_att = ([ //��Ӧ���书
"str":	"unarmed",
"int":	"literate",
"con":	"force",
"cor":	0,
"per":	"huan-rong",
"kar":	"zhouyi",
]);

mapping dbase;
nosave mapping tmp_dbase;

//	The default_ob provides the default values of the dbase. It is set to
//	be master copy of an object.
nosave mixed default_ob;

mixed query_default_object() { return default_ob; }

void set_default_object(mixed ob)
{
	if( userp(this_object())
	&& (geteuid(previous_object()) != ROOT_UID) )
		error("dbase: Only this_object() or object with root uid can set default_ob.\n");
	if( !geteuid() )
		seteuid(getuid());
	default_ob = ob;
	ob->add("no_clean_up", 1);
}

mixed set(string prop, mixed data)
{
	mixed cont;
	int r;

	if( !mapp(dbase) ) dbase = ([]);

	if(prop == "bellicosity" && data < 0)
		data = 0;

	while( (r = strsrch(prop, '/', -1)) > 0 )
	{
		cont = changed_match_path( dbase, prop[0..r-1] );
		if( mapp(cont) )
			return cont[prop[r+1..]] = data;
		data = ([ prop[r+1..]: data ]);
		prop = prop[0..r-1];
	}

	return dbase[prop] = data;
}

varargs mixed query(string prop, int raw)
{
	mixed data;
	int ski,n,fp;

	if( !mapp(dbase) ) return 0;

	// Modified by Find.
	if( userp(this_object()) && (member_array(prop,attribute) != -1) )
	{
		if(!improve_att[prop])
			return dbase[prop]+
			((prop == "str")?
				(((int)dbase["age"] < 40)?((int)dbase["age"]-14):26)
				: 0);
		if(!ski = this_object()->query_skill(improve_att[prop],1))
			return dbase[prop] +
			((prop == "str")?
				(((int)dbase["age"] < 40)?((int)dbase["age"]-14):26)
				: 0);
		n = to_int( (ski-(to_int((int)dbase[prop]*5/10)*10 +9))/5 +2);
		if(n%2) n--;
		return (int)dbase[prop]+((n<0)?0:n)+
			((prop == "str")?
				(((int)dbase["age"] < 40)?((int)dbase["age"]-14):26)
				: 0);
		//  40����ǰÿ��1������1�����. 
	}

	if(prop == "force_factor")
	{
		if(dbase["force"] < dbase["force_factor"])
			return dbase["force"];
		else
			return dbase["force_factor"];
	}

	data = changed_match_path(dbase, prop);

	if( undefinedp(data) && default_ob )
		data = default_ob->query(prop, 1);

	if( raw ) return data;

	if( (fp = functionp(data)) & FP_OWNER_DESTED )
	{
		if( fp & FP_NOT_BINDABLE )
		{
			delete(prop);
			return 0;
		}
		data = set(prop, bind(data, this_object()));
	}

	return evaluate( data, this_object() );
}

int delete(string prop)
{
	mixed cont;
	int r;

	if( !mapp(dbase) ) return 0;

	if( (r = strsrch(prop, '/', -1)) > 0 )
	{
		cont = changed_match_path(dbase, prop[0..r-1]);
		if( mapp(cont) )
			map_delete(cont, prop[r+1..]);
		return 0;
	}

	map_delete(dbase, prop);
	return 1;
}

mixed add(string prop, mixed data)
{
	mixed old;

	if( !mapp(dbase) || !(old = query(prop, 1)) )
		return set(prop, data);

	if( functionp(old) )
		error("dbase: add() - called on a function type property.\n");

	return set(prop, old + data);
}

mapping query_entire_dbase() // Find.
{
	if( userp(this_object())
	&& previous_object()
	&& (previous_object() != this_object())
	&& (geteuid(previous_object()) != ROOT_UID) )
		return copy(dbase);
	else
		return dbase;
}

mixed set_temp(string prop, mixed data)
{
	mixed cont;
	int r;

	if( !mapp(tmp_dbase) )
		tmp_dbase = ([]);

	while( (r = strsrch(prop, '/', -1)) > 0 )
	{
		cont = changed_match_path( tmp_dbase, prop[0..r-1] );
		if( mapp(cont) )
			return cont[prop[r+1..]] = data;
		data = ([ prop[r+1..]: data ]);
		prop = prop[0..r-1];
	}

	return tmp_dbase[prop] = data;
}

varargs mixed query_temp(string prop, int raw)
{
	mixed data;

	if( !mapp(tmp_dbase) )
		return 0;
	data = changed_match_path(tmp_dbase, prop);
	return raw ? data : evaluate(data, this_object());
}

void delete_temp(string prop)
{
	mixed cont;
	int r;

	if( !mapp(tmp_dbase) ) return;

	if( (r = strsrch(prop, '/', -1)) > 0 )
	{
		cont = changed_match_path(tmp_dbase, prop[0..r-1]);
		if( mapp(cont) )
			map_delete(cont, prop[r+1..]);
		return;
	}

	map_delete(tmp_dbase, prop);
}

mixed add_temp(string prop, mixed data)
{
	mixed old;

	if( !mapp(tmp_dbase) || !(old = query_temp(prop, 1)) )
		return set_temp(prop, data);

	if( functionp(old) )
		return old;

	return set_temp(prop, old + data);
}

mapping query_entire_temp_dbase()
{
	if( userp(this_object())
	&& previous_object()
	&& (previous_object() != this_object())
	&& (geteuid(previous_object()) != ROOT_UID) )
		return copy(tmp_dbase);

	return tmp_dbase;
}
