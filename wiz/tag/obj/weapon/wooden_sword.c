#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("ľ��", ({ "wooden sword" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ��ľ�������������úܷ�����\n");
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N��ס�����е�$n��\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_sword(10);
        setup();
}