#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name("��ͷЬ", ({ "laotou xie" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "����˫�ʵغܺõ���ͷЬ��\n");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}

