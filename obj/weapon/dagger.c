// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("ذ��", ({ "bishou", "dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ѿ����൱��ͨ��ذ�ס�\n");
		set("material", "steel");
		set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���뻳�С�\n");	
	}

	init_dagger(4);
	setup();
}