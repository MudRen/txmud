// unarmed_book.c
// by dicky

inherit ITEM;
void create()
{
    set_name("�˻���֮��", ({ "unarmed book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","������д�����˻���֮�� �������ӡ�С�̤ѩɽׯ���ı�־��\n");
		set("value", 100);
		set("material", "paper");
		set("skill", ([
			"party":        "taxue",
			"name":     "unarmed",
			"exp_required":	10000,
			"sen_cost":	15,
			"difficulty":	22,
			"min_skill":    30,
			"max_skill":	100,		
		]) );
	}
}