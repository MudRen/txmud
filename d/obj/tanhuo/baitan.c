// ��̿ wuyantan
// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"��̿"NOR, ({ "bai tan" }) );
	set_weight(4000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�źܹ��صİ�̿�����������Ӳ���ϵĸ��ϡ�\n");
		set("unit", "��");
		set("value", 100000);
	}
}