// skirt.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"ϲ�쳤ȹ"NOR, ({ "red happy skirt", "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ���ۺ�ɫ�ĳ�ȹ�����滹׺�ż�����ɫ��ϲ�֡�\n");
		set("unit", "��");
		set("value", 5);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}