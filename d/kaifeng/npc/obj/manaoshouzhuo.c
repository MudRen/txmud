#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
        set_name(WHT"�������"NOR, ({ "manao shouzhuo" , "shouzhuo"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ֵ���ǵ��������\n");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 4);
                set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");

        }
        setup();
}
