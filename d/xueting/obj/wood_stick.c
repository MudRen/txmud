// wood_stick.c
// by pian

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("���ľ��", ({ "bamboo stick", "stick" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"����һ����ؤ���õĸϹ��õ�ľ����\n");
                set("wield_msg", "$N�ó�һ�������õ�ľ�����������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_stick(17);
        setup();
}
 