#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(  BLU"С����" NOR, ({ "blue flower", "flower" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ͨ�崿��������С����ϸ��֮�£�ȴ��һ������Ļ��ꡣ\n");
                set("unit", "��");
                set("value", 1);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 1);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");

        }
        setup();
}

