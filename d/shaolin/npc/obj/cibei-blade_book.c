// cibei-blade_book.c

inherit ITEM;

void create()
{
	set_name("���ȱ��������š�", ({ "cibei-blade book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","��ɫ�ķ�����д�Ŵȱ��������š�\n");
		set("material", "paper");
		set("skill", ([
			"name":		"cibei-blade",
			"exp_required":	5000,
			"sen_cost":	25,
			"difficulty":	25,
			"max_skill":	40,
		]) );
	}
}

int is_shaolin_book() { return 1; }