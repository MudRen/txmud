#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("���п���", ({ "broad blade" }) );
        set_weight(8000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�����п���������ܴ󣬷���Ҳ��һ�㵶�ء�\n");
                set("value", 5000);
                set("material", "iron");
                set("wield_msg", "$N��������һ�»ӳ�һ��$n��˫�ֽ�����ס���ѡ�\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_blade(40);
        setup();
}
