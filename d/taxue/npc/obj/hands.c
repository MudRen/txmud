// hands.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit HANDS;
void create()
{
	set_name(HIW"��˿����"NOR, ({ "shou tao","shoutao","hand" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("material", "steel");
		set("long", "����һ����˿���ף�������С�̤ѩɽׯ���ı�ǡ�\n");
		set("value", 4000);
		set("armor_prop/armor", 30);
	}
	setup();
}