#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("������", ({ "huge hammer" }) );
        set_weight(20000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "��Ѿ޴���������ж�ʮ���ء�\n");
                set("value", 8000);
                set("material", "iron");
                set("wield_msg", "$N���һ����˫�ֽ�����ס��$n��\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_hammer(40);
        setup();
}

