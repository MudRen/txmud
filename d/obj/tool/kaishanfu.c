// edit by pian

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("��ɽ��", ({ "kai shan fu" }) );
	set_weight(8000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "    һ�ѷ�ľ�����õĿ�ɽ����\n");
		set("unit", "��");
		set("value", 1000);
	}
}