// armor.c
// by dicky

#include <ansi.h> 
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"��������"NOR, ({ "yinliang huxiong","huxiong","armor"}) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "����һ���������أ�������С�̤ѩɽׯ���ı�ǡ�\n");
                set("material", "steel");
                set("value", 5000);
                set("armor_prop/armor", 60);
        }
        setup();
}

