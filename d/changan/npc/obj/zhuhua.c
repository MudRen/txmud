// zhuhua.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIW"����黨"NOR, ({ "zhu hua", "hua"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","����һ���黨��Ҷ���ɴ���Ƕ���ɣ�һ���ͼ�ֵ���ơ�\n");
		set("unit", "��");
		set("material", "gold");
		set("value",8000);
		set("armor_prop/armor", 40);
		set("female_only", 1);
	}
	setup();
}
