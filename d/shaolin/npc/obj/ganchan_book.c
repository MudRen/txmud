// ganchan_book.c

inherit ITEM;

void create()
{
	set_name("���˲��ϲ����š�", ({ "ganchan book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","��ɫ�ķ�����д�Ű˲��ϲ����š�\n");
		set("material", "paper");
		set("skill", ([
			"name":		"ganchan",
			"exp_required":	5000,
			"sen_cost":	25,
			"difficulty":	25,
			"max_skill":	40,
		]) );
	}
}

int is_shaolin_book() { return 1; }
