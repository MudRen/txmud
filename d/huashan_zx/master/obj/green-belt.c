#include <ansi.h>

#include <armor.h>
inherit WAIST;

void create()
{                              
	set_name(HIG"��˿��" NOR, ({"green belt","belt"}) );
	set_weight(500);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ��˿���Ƶ��������ʸкܺã�
�����˼����Ҷ��\n");
		set("unit", "��");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 20);
		set("wear_msg", "$N��$n�ó�ϵ�����ϡ�\n");
	}
	setup();
}
