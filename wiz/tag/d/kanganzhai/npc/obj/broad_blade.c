#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(WHT"���д����"NOR, ({ "broad blade" }) );
        set_weight(12000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ��˶��Ŀ���������û���㹻�������ǻ��費�����ġ�\n");
                set("value", 6000);
                set("material", "steel");
                set("wield_msg", "$N���һ����˫�ֽ�����ס��$n��\n");
                set("unwield_msg", "$N�ɿ������е�$n��\n");
        }

        init_blade(40);
        setup();
}
