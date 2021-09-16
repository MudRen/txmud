// throwing.c

#include <weapon.h>

inherit COMBINED_ITEM;
inherit F_EQUIP;

/* by Find.*/
int is_weapon() {return 1;}

varargs void init_throwing(int damage, int flag)
{
	set("weapon_prop/damage", damage);

	if( clonep(this_object()) ) return;

	/* �����������־����á�*/
	set("flag", flag | SECONDARY);
}

void setup()
{
	// ::setup();
	seteuid(getuid());

	if( clonep(this_object()) ) return;

	set("skill_type", "throwing");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :));
		set("verbs", ({ "throw" }) );
	}
}
