#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIM"紫謦剑"NOR, ({ "ziqing sword","sword" }) );
        set_weight(1200);
        if( clonep() )
		set_default_object(__FILE__);
        else
	{
		set("unit", "把");
		set("long", "这是一把短小锋利的宝剑.\n");
		set("value", 20000);
		set("material", "steel");
        }
	init_sword(40);
	setup();
}
