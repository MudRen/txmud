#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"纤雨裳"NOR, ({ "qianyu shang","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这件纤雨裳是张雨懿的母亲送给女儿的生日礼物。\n");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/personality", 10);
                set("armor_prop/armor", 50);
        }
        setup();
}

