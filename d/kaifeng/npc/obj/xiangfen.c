inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(MAG"���" NOR, ({ "xiang fen"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��������ķ�.\n");
                set("value", 1000);
        }
}

