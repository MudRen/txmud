#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"�����"NOR, ({ "feiyu cloth","cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������������ר�õ����ѡ�\n");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}
