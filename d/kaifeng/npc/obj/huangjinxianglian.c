#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name(HIY"�ƽ�����"NOR, ({ "huangjin xianglian" , "xianglian"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����ֵ���ǵ�������\n");
                set("unit", "��");
                set("value", 100000);
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N����ذ�һ��$n���ڲ����ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�Ӳ����ϳ���������\n");

        }
        setup();
}
