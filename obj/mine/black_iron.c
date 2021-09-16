// black_iron.c
// ����

#include <mine_def.h>

inherit ITEM;

protected int sum;

string query_long();

int is_iron_class_res() { return 1; }
string query_mine_class() { return BLACK_IRON; }
int query_mine_value();

int query_sum() { return sum; }
void add_sum(int n)
{
	sum += n;
	if(sum < 0)
		sum = 0;
}

int set_sum(int n)
{
	if(n < 1)
		return 0;
	sum = n;
	return 1;
}

void create(int arg)
{
	set_name("����", ({ "black iron ingot" }) );
	set_weight(1000);

	if(intp(arg) && (arg > 0))
		sum = arg;

	set("value", (: query_mine_value :) );
	set("unit", "��");
	set("long", (: query_long :));
}

int query_mine_value()
{
	return MINE_D->query_mine_class_value(BLACK_IRON)*sum;
}

string query_selling_msg()
{
	if(sum < 1)
		return "һǮ��ֵ";
	else
		return sprintf("%d ����", sum);
}

string query_long()
{
	string l = "����һ��������";

	if(sum < 1)
		l += "������\nһǮ��ֵ��\n";
	else
		l += sprintf("��Լ\n�� %d Ǯ�ء�\n", sum);

	return l;
}

int query_save_args()
{
	return sum;
}

