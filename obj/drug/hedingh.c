// hedingh.c
// �����¶���
// Find.

inherit POISON;

void create()
{
	set_name("�׶���", ({ "he dinghong" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ź��о綾�ĺ׶��졣\n");
		set("value", 10000);

		// �������¶�����Ʒ������趨��
		set("can_use",2);	// �������ζ���
		set("apply_poison","he_ding_hong");	// �ж��� condition.
	}
}
