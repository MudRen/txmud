// jiandao.c

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("��СȪ����", ({ "jian dao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�Ѻ���������СȪ������\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ�������$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뻳�С�\n");	
	}

	init_dagger(10);
	setup();
}