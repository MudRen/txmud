// ziyansword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIM"���̽�"NOR, ({ "ziyan sword","sword" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ�ѳ�Լ���߰˴磬��������͸����ɫϼ���ķ���������\n");
		set("value", 200000);
		set("material", "steel");
		set("wield_skill",([
			"sword" : 200,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
	}

        init_sword(80);
        setup();
}
