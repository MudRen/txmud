// shoe.c
// by dicky

#include <armor.h>
inherit BOOTS;
#include <ansi.h>

void create()
{
        set_name(GRN"�廨Ь"NOR, ({ "xiuhua xie", "shoe" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long","����һ˫��ɫ�Ĳ����廨Ь��\n");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/dodge", 10);
              }
         setup();
}

