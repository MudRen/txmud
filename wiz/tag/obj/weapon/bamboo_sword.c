#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("��", ({ "bamboo sword" }) );
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ����ϰ�����õ��񽣣����⴦�ò�����������������ͬ�顣\n");
                set("value", 500);
                set("material", "bamboo");
                set("wield_msg", "$N��ס�����е�$n��\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_sword(5);
        setup();
}
