#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"������"NOR, ({ "qianyu shang","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���������������ܲ��ĸ���͸�Ů�����������\n");
                set("value", 5000);
                set("material", "cloth");
                set("armor_prop/personality", 10);
                set("armor_prop/armor", 50);
        }
        setup();
}

