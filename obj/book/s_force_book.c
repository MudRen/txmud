// s_force_book.c

inherit ITEM;

void create()
{
	set_name("�ڹ��ؼ�", ({ "nei gong miji" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����ָ���ڹ��ķ����ؼ���\n");
		set("value", 50000);
		set("material", "paper");
		set("skill", ([
			"name":		"force", // �书����
			"exp_required":	50000,    // ��������Ҫ����;���.
			"sen_cost":	25,      // ���黨����.
			"difficulty":	30,      // �ο� /cmds/std/study.c
			"max_skill":	160,	 // �ܶ�������ߵȼ�.
			"min_skill":	110,
		]) );
	}
}
