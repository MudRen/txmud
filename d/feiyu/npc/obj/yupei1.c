#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"����"NOR, ({ "yu pei"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "�´������ղ��ڣ�Ϊ���������㲡�\n");
                set("value", 10);
                set("material", "glass");
        }
        setup();
}

