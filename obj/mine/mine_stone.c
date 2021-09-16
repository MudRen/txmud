// mine_stone.c
// by Find.

#include <mine_def.h>

inherit ITEM;

protected string mine_class, ucheck_long, unit = "��";
protected int eff_weight, check_flag;

int no_save_in_home() { return 1; }
int is_mine_stone() { return 1; }
int query_check() { return check_flag; }
string query_long();
void set_unit(string arg) { unit = arg; }

varargs int set_check_flag(int flag)
{
	if(check_flag)
		return 0;

	if(flag && eff_weight)
	{
		eff_weight = eff_weight*8/10;
		if(eff_weight < 1)
			eff_weight = 1;
	}

	if(mine_class == BLACK_IRON)
		unit = "Ǯ";

	return check_flag = 1;
}

void create()
{
	switch (random(3))
	{
		case 0:
			set_name("С��ʯ", ({ "ore" }) );
			ucheck_long = "һС���ʯ��\n";
			set_weight(10000);
			break;
		case 1:
			set_name("��ʯ", ({ "ore" }) );
			ucheck_long = "һ���ʯ��\n";
			set_weight(15000);
			break;
		case 2:
			set_name("���ʯ", ({ "ore" }) );
			ucheck_long = "һ����ʯ��\n";
			set_weight(20000);
			break;
	}

	set("unit", "��");
	set("material", "stone");
	set("long", (: query_long :));
	setup();
}

string query_long()
{
	string cm;

	if(!check_flag)
		return ucheck_long;

	if(!mine_class
	|| (eff_weight < 1)
	|| !(cm = MINE_D->chinese_mine_class(mine_class)))
		return "���ʯͷ�ﲻ���κο���ɷ֡�\n";

	return sprintf("����һ�麬��%s�Ŀ�ʯ��\n��Լ���� %d %s%s��\n",
		cm, eff_weight, unit, cm);
}

void set_mine_class(string cs)
{
	if(!previous_object() ||
	(!sscanf(file_name(previous_object()), "/d/%*s")
	&& (geteuid(previous_object()) != ROOT_UID)) )
		return;

	mine_class = cs;

}

string query_mine_class() { return mine_class; }

void set_eff_weight(int n)
{
	if(!previous_object()
	|| (n < 0)
	|| (!sscanf(file_name(previous_object()), "/d/%*s")
	&& (geteuid(previous_object()) != ROOT_UID)) )
		return;

	eff_weight = n;
}

int query_eff_weight() { return eff_weight; }
