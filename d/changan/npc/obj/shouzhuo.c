// shouzhuo.c

#include <ansi.h>

#include <armor.h>
inherit WRISTS;

void create()
{
    set_name(HIG "�������" NOR, ({"cui shouzhuo","shouzhuo","cui"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "һ֧���̵��������\n");
            set("unit", "֧");
            set("value", 20000);
            set("material","glass");
            set("armor_prop/armor",2);
            set("armor_prop/dodge", 2);
            set("wear_msg", "$N��$n�������ϡ�\n");
     }
     setup();
}