// sixhammer.c

#include <weapon.h>

inherit DHAMMER; /* ���ǵ��ִ�,����һ��. by Find.*/

void create()
{
	set_name("���Ǵ�", ({ "sixhammer","hammer" }) );
	set_weight(25000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ������ͭ���������ġ�\n");
		set("material", "iron");
		set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(25);
        setup();
}