#include <weapon.h>
inherit WHIP;

void create()
{       set_name("����", ({ "iron whip" }) );
        set_weight(5000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�����ޣ��������߶೤��");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg", "$N����һ��$n���������С�\n");
                set("unwield_msg", "$N��$n���˼��̣�С�ĵ��������䡣\n");
        }

        init_whip(30);
        setup();
}

