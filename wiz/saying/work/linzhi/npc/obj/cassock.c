//cassock.c  ���ġ�
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�Ϻ�����", ({ "purple cassock","cassock",}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
