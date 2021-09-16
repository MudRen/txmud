// qincai.c

inherit ITEM;

void create()
{
	set_name("«€≤À", ({ "celery" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "’‚ «“ª¿¶œ ¡¡µƒ«€≤À°£\n");
		set("unit", "¿¶");
		set("value", 50);
	}
}
