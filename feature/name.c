// name.c
// by Find.

#include <ansi.h>
#include <dbase.h>

inherit F_NATURE;

nosave string *my_id;
nosave string *my_night_id;
nosave string simple_id;

// mask ���һ�����ǵ�ǰ��
nosave string *mask_id;
nosave string *mask_name;

nomask protected string query_simple_id(string id)
{
	string simple = "", *letters;

	if(!sizeof(id))
		return 0;

	if( sizeof(letters = explode(id, " ")) < 2 )
		return id;

	foreach(string one in letters)
		if(sizeof(one))
			simple += one[0..0];

	return simple;
}

nomask protected void setup_simple_id()
{
	if(!sizeof(my_id))
		return;

	simple_id = query_simple_id(my_id[0]);
}

int set_mask_id(string id)
{
	if( !id || (strlen(id) < 3) )
		return 0;

	if(!mask_id || !sizeof(mask_id))
		mask_id = ({ id });
	else
		mask_id += ({ id });
}

int set_mask_name(string name)
{
	if( !name || (strlen(name) < 2) )
		return 0;

	if(!mask_name || !sizeof(mask_name))
		mask_name = ({ name });
	else
		mask_name += ({ name });
}

varargs void remove_mask_id(string id)
{
	if(!mask_id || !sizeof(mask_id))
		return;

	if(!id)
	{
		mask_id = ({});
		return;
	}

	if(member_array(id, mask_id) == -1)
		return;

	mask_id -= ({ id });
}

varargs void remove_mask_name(string name)
{
	if(!mask_name || !sizeof(mask_name))
		return;

	if(!name)
	{
		mask_name = ({});
		return;
	}

	if(member_array(name, mask_name) == -1)
		return;

	mask_name -= ({ name });
}

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
	setup_simple_id();
}

void set_night_name(string name,string *id)
{
	set("night_name",name);
	set("night_id",id[0]);
	my_night_id = id;
}

int id(string str)
{
	if( this_player() && !this_player()->visible(this_object()) )
		return 0;

	// MASK Ԥ�ȴ���
	if( sizeof(mask_id) )
	{
		if ( (str == mask_id[<1])
		|| (str == query_simple_id(mask_id[<1])) )
			return 1;
		else
			return 0;
	}

	if( !is_day() && sizeof(my_night_id) )
	{
		if(member_array(str, my_night_id) != -1)
			return 1;

		if(str == query_simple_id(my_night_id[0]))
			return 1;

		return 0;
	}

	if(!simple_id)
		setup_simple_id();

	if( (str == simple_id) || (member_array(str, my_id) != -1) )
		return 1;

	return 0;
}

string *parse_command_id_list()
{
	if( mask_id && sizeof(mask_id) )
		return mask_id;

	else if(!is_day() && sizeof(my_night_id))
		return my_night_id;
	else
		return my_id;
}

varargs string name(int raw)
{
	string str;

	if( (raw <= 0) && sizeof(mask_name) )
		return mask_name[<1];
	else
	{
		if(!is_day() && stringp(str=query("night_name")))
			return str;
		else if( stringp(str = query("name")) )
		{
			if(userp(this_object()) && (query("class") == "tangmen"))
				str = "��"+str;

                        if(userp(this_object()) && (query("class") == "taxue"))
                                str = "̤ѩ"+str;

			if( (raw >= 0) || !userp(this_object()) )
				return str;
/*
			if(this_object()->query("thief/num") > 5)
				return sprintf("%s%s%s",HIB,str,NOR);
*/
			if( (query("PKS") > 20)
			&& (query("PKS") >= query("MKS")/2))
				return sprintf("%s%s%s",HIR,str,NOR);
			return str;
		}
                else if(userp(this_object()))
                        return sprintf("%s(%s's user_ob)",file_name(this_object()),geteuid(this_object()));
                else
                        return file_name(this_object());
	}
}

varargs string short(int raw)
{
	string title, nick, str, btitle, id;
	mapping ey;
	object ob = this_object();
	int night = is_day()?0:1;

	if( (raw <= 0) && sizeof(mask_id) )
		id = mask_id[<1];

	else if(!is_day() && sizeof(my_night_id))
		id = my_night_id[0];

	else if(!id = query("id"))
		id = "No_ID";

	if( !stringp(str = query("short")) )
		str = sprintf("%s(%s)", name(raw), capitalize(id));

	if( !this_object()->is_character() )
		return str;

	if( (raw <= 1) && mapp(ey = ob->query("enyi_class")) && sizeof(ey) )
		return str;

	if(ob->query_banghui_id())
		btitle = ob->query_banghui_title();

	if(night && stringp(nick = query("night_nickname")))
		str = sprintf("��%s��%s",nick, str);
	else if( stringp(nick = query("nickname")))
		str = sprintf("��%s��%s",nick, str);

	if(btitle)
		str = sprintf("%s%s%s", btitle, (nick?"":" "), str);
	else if(night && stringp(title = query("night_title")) )
		str = sprintf("%s%s%s", title,(nick?"":" "), str);
	else if(stringp(title = query("title")) )
		str = sprintf("%s%s%s", title, (nick?"":" "), str);
	// ���岿�����

	if(raw <= 0)
	{
		if( !living(ob) )
			str += HIR + query("disable_type") + NOR;

		else if( userp(ob) )
		{
			if(query_temp("boss_behind"))
				str += HIM"<�ϰ������ ����>"NOR;

			else
			{
				int idle;
				object ride;
				string fj;

				if( objectp(ride = query_temp("on_rided")) )
					str += sprintf(HIY "<����%s��>" NOR, ride->name());

				if( strlen(fj = query_temp("fuji_player")) )
					str += sprintf(HIB "<���� %s ��>" NOR, fj);

				if( this_object()->is_ghost() )
					str += HIB "(����) " NOR;
	
				if( query_temp("netdead") )
					str += HIR " <������>" NOR;
					
				if( in_input() )
					str += HIC " <����������>" NOR;
	
				if( in_edit() )
					str += HIY " <�༭������>" NOR;
	
				if( interactive(ob)
				&& (idle = query_idle(ob)) > 120 )
					str += sprintf(HIM " <�ѷ���%s����" NOR, chinese_number(idle/60) );
			}
		}
	}

	return str;
}

varargs string long(int raw)
{
	string str, extra;

	if( !is_day() || !stringp(str = query("night_long")) )
	{
		if( !stringp(str = query("night_long")) )
		{
			if(this_object()->is_character())
			{
				str = short(raw) + "��\n";
				if(stringp(query("long")))
					str += query("long");
			}
			else
			{
				if(!stringp(str = query("long")))
				str = short(raw) + "��\n";
			}
		}
	}

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}
