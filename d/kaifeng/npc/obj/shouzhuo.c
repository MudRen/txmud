#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name(CYN"����"NOR, ({ "shou zhuo" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��С�ɾ��µ�����\n");
                set("unit", "��");
                set("value", 15000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");
        }
        setup();
}

