// waist.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit WAIST;

void create()
{
	set_name(HIW"��������"NOR, ({ "yao dai", "yaodai","waist" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit","��");
		set("material", "steel");
		set("long", "����һ������������������С�̤ѩɽׯ���ı�ǡ�\n");
		set("value", 5000);
		set("armor_prop/armor", 30);
	}
	setup();
}