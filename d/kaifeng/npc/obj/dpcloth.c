#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(WHT"��Ƥ����"NOR, ({ "diaopi dayi","cloth","dayi" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ƥɫ�ܺõĴ��¡�\n");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/personality", 4);
                set("armor_prop/armor", 10);
        }
        setup();
}
