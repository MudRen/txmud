#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("����", ({ "sword" }) );
        set_weight(4000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�ѳ�����������ı���֮һ�ˡ�");
                set("value", 2500);
                set("material", "iron");
                set("wield_msg", "$N��ৡ��ذγ�һ��$n���������С�\n");
                set("unwield_msg", "$N���꡹�ؽ�$n����˽����С�\n");
        }

        init_sword(25);
        setup();
}
