// head.c
// by dicky

#include <armor.h>
#include <ansi.h> 
inherit HEAD;

void create()
{
	set_name(HIW"��˿ͷ��"NOR, ({ "tou jing", "toujing","head" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("material", "steel");
		set("long", "����һ����˿ͷ��������С�̤ѩɽׯ���ı�ǡ�\n");
		set("value", 5000);
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", -2);
	}
	setup();
}