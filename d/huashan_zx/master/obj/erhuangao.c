// erhuangao.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( HIM"��������"NOR, ({  "erhuang ao" }) );
        set_weight(100);
        set("long", HIG"һ��������˿�ʳ�������˵�������߼���˿��֯�ɵģ����������ԵĹ�Ч��\n"NOR);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 6000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", -30);
                set("armor_prop/literate",30);
        }
        setup();
}
