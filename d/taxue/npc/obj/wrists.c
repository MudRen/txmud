// wrists.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit WRISTS;

void create()
{
	set_name(HIW"��������"NOR, ({"hu wan","huwan","wrists" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("value",4000);
		set("long", "����һ˫��������������С�̤ѩɽׯ���ı�ǡ�\n");
		set("material", "steel");
		set("armor_prop/armor", 30);
	}
	setup();
}
