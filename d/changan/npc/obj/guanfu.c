// guanfu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��Ʒ�ٷ�", ({ "guan fu", "fu" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","����һ����Ʒ�ٷ���\n");
		set("unit", "��");
		set("value",2000);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
