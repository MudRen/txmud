// liuyun-sword.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
	set_name( WHT"���ƽ�" NOR, ({ "liuyun sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
���ƽ��ǻ�ɽ���ڴ�ʦ����������ʱ�����ı�����
���������ߴ磬��һ��ŷ֣��볤һ��һ�磬��������
�������˽���˵�����������������������������ʹ��
������һЩ��Ϊ���ܵĹ�Ч��
LONG
);

		set("valid_number",1);
		set("value", 30000);
		set("material", "steel");
		set("wield_msg", WHT"$N��ˢ����һ�����һ�����������$n�������С�\n"NOR);
		set("unequip_msg", WHT"$N�����е�$n��������Ľ��ʡ�\n"NOR);
		set("weapon_prop/courage", 10);
		set("weapon_prop/intelligence", 10);
		set("weapon_prop/personality", 10);
	
		// װ���˱�����Ҫ��ҵ��书 sword >50 ,parry >50.
		set("wield_skill",([
		"sword" : 50,
		"parry" : 50,
	]));
	
	        // װ���˱�����Ҫ�������޴��� 300,�����������.
		set("wield_ability",([
		"max_force" : 300,
		"combat_exp" : 50000,
	]));
}
        init_sword(60);
        setup();
}
