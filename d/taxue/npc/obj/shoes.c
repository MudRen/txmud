// cloth.c
// by dicky

#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIY"�Ŷ���Ь"NOR, ({ "jiuer maxie","maxie","shoes" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", "����һ˫�Ŷ���Ь��������С�̤ѩɽׯ���ı�ǡ�\n");
                set("material", "cloth");
		set("value", 5000);
		set("armor_prop/dodge", 10);
		set("armor_prop/armor", 30);
        }
        setup();
}
