// yayifu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("���۷�", ({ "yayi cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����۴��Ĺٷ���\n");
		set("unit", "��");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
        }
	setup();
}