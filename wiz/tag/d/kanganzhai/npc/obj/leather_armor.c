// leather_armor.c

#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("Ƥ��", ({ "leather armor" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ʵ��Ƥ�ף���������Ѿ���Щ�����ˡ�\n");
                set("unit", "��");
                set("value", 4000);
                set("material", "leather");
                set("armor_prop/armor", 30);
        }
        setup();
}

