// torch.c
// This is a example object for light_ob.
// by Find.

inherit LIGHT_OB;

void create()
{
	set_name("���", ({ "torch" }) );

	set_weight(300);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "ֻ");
		set("long", "����һֻ���,����Ե�ȼ��(light)��\n");
		set("value", 100);
		set("material", "wood");

		// ʹ light_ob ����Ķ�������������ã�Ĭ�ϵĶ�����'��ȼ'
		set("light_verb","��ȼ");

		// light_ob ��ȼ��ɷ����ʱ��(��λ����)����������ã�Ĭ�ϵ�ʱ���� 60
		set("light_time",240);
	}
	setup();
}