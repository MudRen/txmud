// iron_cu.c

#include <mine_def.h>

inherit ITEM;

string query_long();

int is_iron_class_res() { return 1; }
string query_mine_class() { return IRON_RES_CU; }
int query_mine_value();

void create(int arg)
{
	set_name("������", ({ "cast iron ingot" }) );
	set_weight(0);

	if(intp(arg) && (arg >= 100))
		set_weight(arg);

	set("value", (: query_mine_value :) );
	set("unit", "��");
	set("long", (: query_long :));
}

int query_mine_value()
{
	int wt;

	if( (wt = query_weight()) < 100 )
		return 0;

	return MINE_D->query_mine_class_value(IRON_RES_CU)*query_weight()/100;
}

string query_selling_msg()
{
	int w = query_weight();

	if(w < 100)
		return "һǮ��ֵ";
	else
		return sprintf("%d ����", w/100);
}

string query_long()
{
	int w = query_weight();
	string l = "����һ���������";

	if(w < 100)
		l += "������\nһǮ��ֵ��\n";
	else
		l += sprintf("��Լ\n�� %d ���ء�\n", w/100);

	return l;
}

int query_save_args()
{
	return query_weight();
}

