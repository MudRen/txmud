#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("ľ��", ({ "wood sword", "sword" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
                set("material", "wood");
                set("long", 
"����һ�Ѻ���ľ����\n");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(2);
        setup();
}
