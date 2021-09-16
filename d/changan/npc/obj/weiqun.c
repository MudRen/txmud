// weiqun.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("油腻围裙", ({ "wei qun", "qun" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
		set("long", "这是一件做饭时围的围裙，上面满是油污的。\n");
		set("unit", "件");
		set("value", 10);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}