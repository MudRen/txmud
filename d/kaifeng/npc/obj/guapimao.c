#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(WHT"��Ƥñ"NOR, ({ "guapi mao" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ƕ��ʵغܺõĹ�Ƥñ��\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

