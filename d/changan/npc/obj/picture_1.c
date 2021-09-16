// picture_1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"º®Ã·Ó³Ñ©Í¼"NOR, ({ "picture", "tu"  }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "·ù");
		set("value", 50000);
		set("long","Ò»·ùº®Ã·Í¼£¨³¤ÃèÊö£©\n");
	}
	setup();
}
