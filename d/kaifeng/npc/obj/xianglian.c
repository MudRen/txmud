#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIW"����"NOR, ({ "xiang lian" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�������ܾ�ϸ��������\n");
                set("unit", "��");
                set("value", 50000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n���ڲ����ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�Ӳ����ϳ���������\n");
        }
        setup();
}
