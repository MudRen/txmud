// windsword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIM"飘风剑"NOR, ({ "wind sword","sword" }) );
        set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "把");
		set("long", "飘风剑和落雨剑在绯雨阁里始终是两个谜。\n");
		set("value", 200);
		set("material", "iron");
		set("valid_number",1);
	}

        init_sword(10);
        setup();
}

