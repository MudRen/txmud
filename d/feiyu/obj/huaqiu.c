#include <armor.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"С����" NOR, ({ "flower ball", "ball" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��������ɫ���ǳ�Ư����С����\n");
                set("unit", "��");
                set("value", 100);
                set("material", "plant");
        }
        setup();
}
