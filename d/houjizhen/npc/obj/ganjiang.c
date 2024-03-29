// ganjiangsword.c
// by dicky

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIB"干将"NOR, ({ "ganjiang sword","sword" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
		set("no_get", 1);
		set("no_give", 1);
		set("long", "此剑长四尺，黝黑黝黑由万年玄铁所铸，无锋无刃，
却杀气森然，实乃上古第一神兵。\n");
		set("value", 200000);
		set("material", "blacksteel");
		set("wield_msg", HIY"$N唰的一声从背后抽出神兵干将，但见寒气逼人，杀雾迷茫，
方圆之内轰然雷声滚滚，肃杀万分。\n"NOR);             
                set("unwield_msg", BLU "$N将干将插回剑梢，杀气顿减，紫光也跟着消失。\n" NOR);
		set("wield_skill",([
			"sword" : 100,
		]));
		set("wield_ability",([
			"combat_exp" : 50000,
		]));
	}
        init_sword(120);
        setup();
}
