// cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIC"�಼����" NOR, ({ "qingbu cloth" }) );
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("wear_msg", "$N��$n�ó��������ϡ�\n");
	}
	setup();
}
