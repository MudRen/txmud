// zhen.c

// ������ڰ��������ó���ûʲô���壬
// �������̺���Ҳ��һ����ʲô�ı�̬
// �ã��ձ������Ͻ�Ϊ������combined.

// Modified by Find.

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("ϸ��", ({ "zhen" }) );
	if( clonep() )
	set_default_object(__FILE__);

	else
	{
		set("base_weight", 50);
		set("base_unit", "��");
		set("unit","Щ");
		set("long", "����һ�������൱��ͨ��ϸ�룬������Լ�м�Ǯ���ҡ�\n");
		set("base_value", 10);
		set("material", "steel");
		set("wield_msg", "$N���ĵشӻ�������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$nС������ķ��뻳�����С�\n");
	}

	set_amount(1);
	init_throwing(15);
	setup();
}