// ľ̿ mutan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"��̿"NOR, ({ "jiao tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�ź���ͨ�Ľ�̿����������ʱ�ĸ��ϡ�\n");
		set("unit", "��");
		set("value", 3000);
	}
}