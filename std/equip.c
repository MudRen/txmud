// equip.c
// by Find.

#include <ansi.h>
#include <mangle.h>
inherit ITEM;
inherit F_EQUIP;

string w_bad = "�𻵵�",w_break = "�ϵ���";
string a_bad = "�𻵵�",a_break = "���õ�";

void setup()
{
	string name = query("name"), level;

	if( this_object()->is_armor() )
	{
		int n = query("armor_prop/armor");

		if(n > 90)
			level = HIY"��"NOR;
		else if(n > 40)
			level = HIW"��"NOR;

		if( !query("armor_prop/dodge")
		&& (weight() >= 3000) )
			set("armor_prop/dodge", - weight() / 3000 );
	}

	if( this_object()->is_weapon() )
	{
		int n = query("weapon_prop/damage");

		if(n > 100)
			level = HIY"��"NOR;
		else if(n > 60)
			level = HIW"��"NOR;

		if( !query("weapon_prop/dodge")
		&& (weight() >= 3000) )
			set("weapon_prop/dodge", - weight() / 3000 );
	}

	if(!name)
		return;

	if(query_shadowed())	// ���ر���
		name += HIB"��"NOR;

	if(level)
		name += level;

	set("name", name);
}

varargs string name(int raw)
{
	string name;
	int m;

	name = item::name(raw);

	if(this_object()->is_weapon())
	{
		m = this_object()->query("weapon_mangle");
		if( m >= W_MAX_MANGLE )
			return w_break + name;
		if( m >= W_MAX_MANGLE/2 )
			return w_bad + name;
	}

	else if( this_object()->is_armor())
	{
		m = this_object()->query("armor_mangle");
		if( m >= A_MAX_MANGLE )
			return a_break + name;
		if( m >= A_MAX_MANGLE/2 )
			return a_bad + name;
	}

	return name;
}
