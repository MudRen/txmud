#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"������"NOR, ({ "ziqing sword","sword" }) );
        set_weight(1200);
        if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("unit", "��");
		set("long", "����һ�Ѷ�С�����ı���.\n");
		set("value", 20000);
		set("material", "steel");
        }
	init_sword(40);
	setup();
}
