#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("ϸ��", ({ "thin sword" }) );
        set_weight(2500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ��ϸ������ƮƮ�ģ�Ů���Ӽ��õ����⡣");
                set("value", 2000);
                set("material", "iron");
                set("wield_msg", "$N��ৡ��ذγ�һ��$n���������С�\n");
                set("unwield_msg", "$N���꡹�ؽ�$n����˽����С�\n");
        }

        init_sword(20);
        setup();
}
