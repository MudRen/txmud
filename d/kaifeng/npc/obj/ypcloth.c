#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"��ƤС��"NOR, ({ "yangpi xiaoshan","cloth","xiaoshan" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��Ƥɫ�ܺõĴ��¡�\n");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/personality", 1);
                set("armor_prop/armor", 6);
        }
        setup();
}
