//hunt-fork.c �Բ�
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("�Բ�", ({ "hunter fork","fork","hf" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ϸ�����Բ棬����һ��������\n");
                set("value", 4000);
                set("material", "iron");
                set("wield_msg", "$N��$n����߬��������ŵĿ������ܡ�\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }
        init_fork(30);
        setup();
}

