// weiqun.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����Χȹ", ({ "wei qun", "qun" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("long", "����һ������ʱΧ��Χȹ�������������۵ġ�\n");
		set("unit", "��");
		set("value", 10);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}