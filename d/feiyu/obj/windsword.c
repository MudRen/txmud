// windsword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_CONTROL;

void create()
{
        set_name(HIM"Ʈ�罣"NOR, ({ "wind sword","sword" }) );
        set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "Ʈ�罣�����꽣��������ʼ���������ա�\n");
		set("value", 200);
		set("material", "iron");
		set("valid_number",1);
	}

        init_sword(10);
        setup();
}

