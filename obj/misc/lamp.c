// lamp.c
// This is a example object for light_ob.
// by Find.

inherit LIGHT_OB;

void create()
{
	set_name("ͭ�͵�", ({ "lamp" }) );

	set_weight(400);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "յ");
		set("long", "����һյͭ�͵�,����Ե�ȼ��(light)��\n");
		set("value", 200);
		set("material", "copper");

		// ʹ light_ob ����Ķ�������������ã�Ĭ�ϵĶ�����'��ȼ'
		set("light_verb","����");

		// light_ob ��ȼ��ɷ����ʱ��(��λ����)����������ã�Ĭ�ϵ�ʱ���� 60
		set("light_time",240);
	}
	setup();
}