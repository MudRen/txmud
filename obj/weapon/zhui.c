// dart.c

#include <weapon.h>

inherit THROWING;

int through_armor() { return 1; }

void create()
{
	set_name("͸��׶", ({ "toujia zhui" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ֦���ź���ĸ�׶��ר��������͸���׵İ�����\n");
		set("unit", "Щ");
		set("base_unit", "֦");
		set("base_weight", 100);
		set("base_value", 100);
	}

	set_amount(1);
	init_throwing(20);
	setup();
}
