// fw_gun.c

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("���Ȩ��", ({ "feiyu quanzhang", "zhang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
       set("unit", "��");
       set("long", "������������Ȩ���ķ��ȣ���˵���������");
        set("value", 99);
		set("material", "wood");
        set("wield_msg", "$N�����ذγ�һ��$n!\n");
        set("unwield_msg", "$N�������е�$n��\n");
	}

    init_sword(320);
	setup();
}
