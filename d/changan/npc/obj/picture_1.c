// picture_1.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"��÷ӳѩͼ"NOR, ({ "picture", "tu"  }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("value", 50000);
		set("long","һ����÷ͼ����������\n");
	}
	setup();
}
