#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIB"������Ӱ"NOR, ({ "nishang yanying","cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����·���ҹ����ĸ��ΪŮ�����ģ���������������\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/personality", 8);
                set("armor_prop/armor", 20);
        }
        setup();
}
