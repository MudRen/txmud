// force_book.c

inherit ITEM;

void create()
{
	set_name("�������󷨡�", ({ "force book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ������ﳣ���Ľ������ڹ����鼮��\n");
		set("value", 4000);
		set("material", "paper");
		set("skill", ([
			"name":		"force", // �书����
			"exp_required":	10000,    // ��������Ҫ����;���.
			"sen_cost":	25,      // ���黨����.
			"difficulty":	30,      // �ο� /cmds/std/study.c
			"max_skill":	70,	 // �ܶ�������ߵȼ�.
		]) );
	}
}