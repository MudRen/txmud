// table.c

inherit ITEM;

int is_sxg() { return 1; }

void create()
{
	set_name("��ľ�����", ({ "double happy table"}) );

	set_weight(5000000);
	set_max_encumbrance(800000);

	set("no_get", 1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("position", "on");
		set("prep", "on");
		set("unit", "��");
		set("long", "����һ�ź�ľ������������㹻
��ʮ����ͬʱ�Է���\n");
		set("value", 1);
	}
}

int is_container() { return 1; }
