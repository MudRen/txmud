#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("����", ({ "blade" }) );
        set_weight(4000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ��������������ı���֮һ�ˡ�");
                set("value", 2500);
                set("material", "iron");
                set("wield_msg", "$N��ৡ��ذγ�һ��$n���������С�\n");
                set("unwield_msg", "$N���꡹�ؽ�$n����˵����С�\n");
        }

        init_blade(25);
        setup();
}
