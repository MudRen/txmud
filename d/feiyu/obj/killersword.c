#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIR"ɱ��֮��"NOR, ({ "killer sword","sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "ɱ��֮����������Ӱ�ɱר�õ�������\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N�ӽ�������һ���ʺ��$n�������У�������Χɱ������\n");
		set("unwield_msg", "$N�����е�$n��ؽ����С�\n");

		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
	}
        init_sword(70);

        setup();
}

