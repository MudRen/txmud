//zang-blade.c 
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name("�ص�", ({ "zang blade","blade","zb" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����λεĲص�������ĵ������ź��⡣\n");
                set("value",2500);
                set("material", "iron");
                set("wield_msg", "$N��ৡ���һ���ӱ�����һ��$n��\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
        }
        init_blade(30);
        setup();
}
