#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"����"NOR, ({ "er huan" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��С�ɾ��µĶ�����\n");
                set("unit", "��");
                set("value", 10000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 2);
                set("wear_msg", "$N����ذ�һ��$n���ڶ����ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�Ӷ����ϳ���������\n");
        }
        setup();
}
