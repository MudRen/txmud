#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("�ڳ���", ({ "black cloth","cloth" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��һ��������Ӱ�ɱʱ�������ѡ�\n");
                set("value", 800);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

