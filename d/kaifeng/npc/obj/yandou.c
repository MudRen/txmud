// yandou.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"�̶�"NOR, ({ "yan dou" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",1000);
                set("material", "gold");
                set("long", "����һ��������̶���\n");
        }
        setup();
}
