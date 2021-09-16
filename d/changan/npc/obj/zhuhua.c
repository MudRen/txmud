// zhuhua.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIW"镶翠珠花"NOR, ({ "zhu hua", "hua"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","这是一朵珠花，叶子由翠镶嵌而成，一看就价值不菲。\n");
		set("unit", "朵");
		set("material", "gold");
		set("value",8000);
		set("armor_prop/armor", 40);
		set("female_only", 1);
	}
	setup();
}
