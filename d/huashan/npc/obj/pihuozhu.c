#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIR"�ٻ���"NOR, ({ "pihuo zhu","zhu" }) );
	if ( clonep() )
              set_default_object(__FILE__);
     	else {
     	set("long",WHT"����һֻ�ٻ��飬��ǧ��Ѫ���ڵ����Ի�Ͷ�����Ȼ�Ŀ�����\n"NOR);
	set_weight(3000);
	
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 100);
	}
	setup();
}
