#include <weapon.h>
inherit STICK;

void create()
{
        set_name("���", ({ "bamboo stick" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ����ϰ�����õ������\n");
                set("value", 500);
                set("material", "bamboo");
                set("wield_msg", "$N��ס�����е�$n��\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_stick(5);
        setup();
}
