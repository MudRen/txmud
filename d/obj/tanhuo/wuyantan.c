// ����̿ wuyantan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"����̿"NOR, ({ "wuyan tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�źܹ��ص�����̿����������ʱ�ĸ��ϡ�\n");
		set("unit", "��");
		set("value", 10000);
	}
}