#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"����"NOR, ({ "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����������ɱ��ר�Ŵ����·���\n");
                set("value", 3000);
                set("material", "cloth");
                set("armor_prop/armor", 50);
        }
        setup();
}
