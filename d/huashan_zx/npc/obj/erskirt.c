// huashan erhuang.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name( HIY"��Ƴ�ȹ"NOR, ({  "erhuang skirt","skirt" }) );
        set_weight(100);
        set("long", "����һ�������Ķ��ɫ˿�ʳ�����һ����֪���ǽ��ϵĹ�˿�Ƴɵġ�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("armor_prop/dodge", -5);
		set("female_only", 1);
        }
        setup();
}
